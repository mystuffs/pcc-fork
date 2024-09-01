#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <err.h>
#include <errno.h>

struct mem_info {
	uint64_t mem_total;
	uint64_t mem_free;
	uint64_t mem_avail;
	uint64_t shmem;
	uint64_t buffers;
	uint64_t cache;
	uint64_t swap_total;
	uint64_t swap_free;
};

static const char size_suffix[7] = { 'B', 'K', 'M', 'G', 'T', 'P', '\0' };

#define PRETTY_MAX_SIZE    (2048)
#define ARRAY_SZ(x)        (sizeof(x) / sizeof(*x))

#define PRETTY_EXPO_B    (1)
#define PRETTY_EXPO_K    (2)
#define PRETTY_EXPO_M    (3)
#define PRETTY_EXPO_G    (4)
#define PRETTY_EXPO_T    (5)
#define PRETTY_EXPO_P    (6)

static uint64_t conv_to_u64(const char *s)
{
	uint64_t value;
	char *eptr;

	value = strtoull(s, &eptr, 10);
	if (errno != 0)
		err(EXIT_FAILURE, "strtoull()");

	if (eptr == s)
		errx(EXIT_FAILURE, "no digits are available in that string.");

	return (value);
}

static inline double power(int base, int expo)
{
        double mul2;

	if (expo == 0)
		return (1);

	mul2 = 1.0;
	while (expo--)
		mul2 *= (double)base;
        return (mul2);
}

static char *pretty_size(uint64_t size, uint32_t expo, int is_si, int do_pretty)
{
        uint64_t bytes;
	char *p;
	int base, i, format_size;

	base = is_si ? 1000 : 1024;
	/* Convert from kB to bytes. */
	bytes = size * (uint64_t)1024;

	p = calloc(PRETTY_MAX_SIZE, sizeof(char));
	if (p == NULL)
		err(EXIT_FAILURE, "calloc()");

	if (do_pretty) {
		for (i = 0; ARRAY_SZ(size_suffix); i++) {
			if (is_si) {
				format_size = snprintf(
					p, PRETTY_MAX_SIZE, "%.1f%ci",
					(float)(bytes / power(base, i)),
					size_suffix[i]);
				if (format_size <= 4)
					return (p);

				format_size = snprintf(
					p, PRETTY_MAX_SIZE, "%ld%ci",
					(long)(bytes / power(base, i)),
					size_suffix[i]);
				if (format_size <= 4)
					return (p);
			} else {
				format_size = snprintf(
					p, PRETTY_MAX_SIZE, "%.1f%c",
					(float)(bytes / power(base, i)),
					size_suffix[i]);
				if (format_size <= 4)
					return (p);

			        format_size = snprintf(
					p, PRETTY_MAX_SIZE, "%ld%c",
					(long)(bytes / power(base, i)),
					size_suffix[i]);
				if (format_size <= 4)
					return (p);
			}
		}
	} else {
		switch (expo) {
		case 0:
			snprintf(p, PRETTY_MAX_SIZE, "%lld",
				 (uint64_t)(bytes / base));
		        break;
		case 1:
			snprintf(p, PRETTY_MAX_SIZE, "%lld", bytes);
		        break;
		default:
			snprintf(p, PRETTY_MAX_SIZE, "%lld",
				 (uint64_t)(bytes / power(base, expo - 1)));
		        break;
		}

	        return (p);
	}
}

static char *read_meminfo_file(void)
{
	int fd;
	char buf[200];
	char *p;
	size_t extra_bytes, prev_bytes;

	fd = open("/proc/meminfo", O_RDONLY);
	if (fd == -1) {
		if (errno == ENOENT)
			errx(EXIT_FAILURE, "cannot find /proc/meminfo. Is /proc mounted?");
		err(EXIT_FAILURE, "open()");
	}

	p = calloc(1, sizeof(char));
	if (p == NULL)
		err(EXIT_FAILURE, "calloc()");

	memset(buf, '\0', sizeof(buf));
	extra_bytes = prev_bytes = 0;
	while (read(fd, buf, sizeof(buf) - 1) > 0) {
		if (extra_bytes <= sizeof(buf)) {
			extra_bytes = sizeof(buf) * 4;
			p = realloc(p, prev_bytes + extra_bytes);
			if (p == NULL)
				err(EXIT_FAILURE, "realloc()");
			prev_bytes += extra_bytes;
		} else {
			extra_bytes -= sizeof(buf);
		}

		memcpy(p + strlen(p), buf, sizeof(buf));
		memset(buf, '\0', sizeof(buf) - 1);
        }
	close(fd);
	/* fprintf(stdout, "%s", p); */
	return (p);
}

static uint64_t get_mem_kv(const char *mbuf, const char *key)
{
	char *spos, *p;
	size_t pos;
	uint64_t val;

	p = strdup(mbuf);
	if (p == NULL)
		err(EXIT_FAILURE, "strdup()");

	spos = strstr(p, key);
	if (spos == NULL)
		errx(EXIT_FAILURE,
		     "cannot get value of the provided key: '%s'", key);

	/* Equavalent of strcspn().
	   See: https://codebrowser.dev/glibc/glibc/string/strcspn.c.html#32 */
        pos = strchr(spos, '\n') - spos;
	spos[pos] = '\0';
        while (*spos != ' ')
		spos++;
	while (*spos == ' ')
		spos++;
	pos = strcspn(spos, " ");
	spos[pos] = '\0';

	val = conv_to_u64(spos);
	free(p);
        return (val);
}

static void do_collect_meminfo(struct mem_info *mi, const char *mbuf)
{
	mi->mem_total = get_mem_kv(mbuf, "MemTotal:");
	mi->mem_free = get_mem_kv(mbuf, "MemFree:");
	mi->mem_avail = get_mem_kv(mbuf, "MemAvailable:");
	mi->shmem = get_mem_kv(mbuf, "Shmem:");
        mi->buffers = get_mem_kv(mbuf, "Buffers:");
	mi->cache = get_mem_kv(mbuf, "Cached:");

	mi->swap_total = get_mem_kv(mbuf, "SwapTotal:");
	mi->swap_free = get_mem_kv(mbuf, "SwapFree:");
}

static void print_collected_info(struct mem_info *mi)
{
	uint64_t mem_used;

	/* TODO: Use arrow operator. */
        mem_used = (*mi).mem_total - mi->mem_avail;

	fprintf(stdout, "%s\n", pretty_size(mi->mem_total, 1, 0, 1));
	fprintf(stdout, "%s\n", pretty_size(mem_used, 1, 0, 1));
	fprintf(stdout, "%s\n", pretty_size(mi->mem_free, 1, 0, 1));
	fprintf(stdout, "%s\n", pretty_size(mi->shmem, 1, 0, 1));
}

int main(void)
{
	char *mbuf;
	uint64_t val;
	struct mem_info mi;

	mbuf = read_meminfo_file();
	do_collect_meminfo(&mi, mbuf);

	/* TODO: Pretty print and pretty size. */
	/* uint64_t mem_used; */

	/* mem_used = mi.mem_total - mi.mem_avail; */
	/* fprintf(stdout, "%s\n", pretty_size(mi.mem_total, 1, 0, 1)); */
	/* fprintf(stdout, "%s\n", pretty_size(mem_used, 1, 0, 1)); */
	/* fprintf(stdout, "%s\n", pretty_size(mi.mem_free, 1, 0, 1)); */
	/* fprintf(stdout, "%s\n", pretty_size(mi.shmem, 1, 0, 1)); */
	
	/* fprintf(stdout, "%lu\n", mi.mem_free); */
	/* fprintf(stdout, "%lu\n", mi.mem_avail); */

	print_collected_info(&mi);

	/* fprintf(stdout, "%s\n", pretty_size(3903652, PRETTY_EXPO_G, 1, 0)); */
	/* fprintf(stdout, "%lf\n", power(5, 50)); */

	/* mbuf = read_meminfo_file(); */
        /* val = get_mem_kv(mbuf, "MemTotal:"); */
	/* fprintf(stdout, "%llu\n", val); */
}
