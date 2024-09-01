#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <err.h>

static void curl_test(void)
{
        CURL *curl;
	CURLcode curl_code;

	curl = curl_easy_init();
	if (curl == NULL)
		errx(EXIT_FAILURE, "curl_easy_init()");

	curl_easy_setopt(curl, CURLOPT_URL, "https://www.gnu.org/licenses/gpl-3.0.txt");
        curl_code = curl_easy_perform(curl);
	if (curl_code != CURLE_OK)
		errx(EXIT_FAILURE, "curl_easy_perform() != CURLE_OK");

	curl_easy_cleanup(curl);
}

int main(void)
{
	curl_test();
}
