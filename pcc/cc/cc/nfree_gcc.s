	.file	"nfree.c"
	.text
	.section	.rodata
	.type	size_suffix, @object
	.size	size_suffix, 7
size_suffix:
	.string	"BKMGTP"
.LC0:
	.string	"strtoull()"
	.align 8
.LC1:
	.string	"no digits are available in that string."
	.text
	.type	conv_to_u64, @function
conv_to_u64:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	leaq	-16(%rbp), %rcx
	movq	-24(%rbp), %rax
	movl	$10, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	strtoull@PLT
	movq	%rax, -8(%rbp)
	call	__errno_location@PLT
	movl	(%rax), %eax
	testl	%eax, %eax
	je	.L2
	leaq	.LC0(%rip), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	err@PLT
.L2:
	movq	-16(%rbp), %rax
	cmpq	%rax, -24(%rbp)
	jne	.L3
	leaq	.LC1(%rip), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	errx@PLT
.L3:
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	conv_to_u64, .-conv_to_u64
	.type	power, @function
power:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	cmpl	$0, -24(%rbp)
	jne	.L6
	movsd	.LC2(%rip), %xmm0
	jmp	.L7
.L6:
	movsd	.LC2(%rip), %xmm0
	movsd	%xmm0, -8(%rbp)
	jmp	.L8
.L9:
	pxor	%xmm0, %xmm0
	cvtsi2sdl	-20(%rbp), %xmm0
	movsd	-8(%rbp), %xmm1
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
.L8:
	movl	-24(%rbp), %eax
	leal	-1(%rax), %edx
	movl	%edx, -24(%rbp)
	testl	%eax, %eax
	jne	.L9
	movsd	-8(%rbp), %xmm0
.L7:
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	power, .-power
	.section	.rodata
.LC3:
	.string	"calloc()"
.LC4:
	.string	"%.1f%ci"
.LC5:
	.string	"%ld%ci"
.LC6:
	.string	"%.1f%c"
.LC7:
	.string	"%ld%c"
.LC8:
	.string	"%lld"
	.text
	.type	pretty_size, @function
pretty_size:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$72, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -56(%rbp)
	movl	%esi, -60(%rbp)
	movl	%edx, -64(%rbp)
	movl	%ecx, -68(%rbp)
	cmpl	$0, -64(%rbp)
	je	.L11
	movl	$1000, %eax
	jmp	.L12
.L11:
	movl	$1024, %eax
.L12:
	movl	%eax, -24(%rbp)
	movq	-56(%rbp), %rax
	salq	$10, %rax
	movq	%rax, -32(%rbp)
	movl	$1, %esi
	movl	$2048, %edi
	call	calloc@PLT
	movq	%rax, -40(%rbp)
	cmpq	$0, -40(%rbp)
	jne	.L13
	leaq	.LC3(%rip), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	err@PLT
.L13:
	cmpl	$0, -68(%rbp)
	je	.L14
	movl	$0, -20(%rbp)
.L28:
	cmpl	$0, -64(%rbp)
	je	.L15
	movl	-20(%rbp), %eax
	cltq
	leaq	size_suffix(%rip), %rdx
	movzbl	(%rax,%rdx), %eax
	movsbl	%al, %ebx
	movq	-32(%rbp), %rax
	testq	%rax, %rax
	js	.L16
	pxor	%xmm2, %xmm2
	cvtsi2sdq	%rax, %xmm2
	movsd	%xmm2, -80(%rbp)
	jmp	.L17
.L16:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
	movsd	%xmm0, -80(%rbp)
.L17:
	movl	-20(%rbp), %edx
	movl	-24(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	power
	movsd	-80(%rbp), %xmm1
	divsd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	cvtsd2ss	%xmm1, %xmm0
	pxor	%xmm3, %xmm3
	cvtss2sd	%xmm0, %xmm3
	movq	%xmm3, %rdx
	movq	-40(%rbp), %rax
	movl	%ebx, %ecx
	movq	%rdx, %xmm0
	leaq	.LC4(%rip), %rdx
	movl	$2048, %esi
	movq	%rax, %rdi
	movl	$1, %eax
	call	snprintf@PLT
	movl	%eax, -44(%rbp)
	cmpl	$4, -44(%rbp)
	jg	.L18
	movq	-40(%rbp), %rax
	jmp	.L19
.L18:
	movl	-20(%rbp), %eax
	cltq
	leaq	size_suffix(%rip), %rdx
	movzbl	(%rax,%rdx), %eax
	movsbl	%al, %ebx
	movq	-32(%rbp), %rax
	testq	%rax, %rax
	js	.L20
	pxor	%xmm4, %xmm4
	cvtsi2sdq	%rax, %xmm4
	movsd	%xmm4, -80(%rbp)
	jmp	.L21
.L20:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
	movsd	%xmm0, -80(%rbp)
.L21:
	movl	-20(%rbp), %edx
	movl	-24(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	power
	movsd	-80(%rbp), %xmm1
	divsd	%xmm0, %xmm1
	cvttsd2siq	%xmm1, %rdx
	movq	-40(%rbp), %rax
	movl	%ebx, %r8d
	movq	%rdx, %rcx
	leaq	.LC5(%rip), %rdx
	movl	$2048, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf@PLT
	movl	%eax, -44(%rbp)
	cmpl	$4, -44(%rbp)
	jg	.L22
	movq	-40(%rbp), %rax
	jmp	.L19
.L15:
	movl	-20(%rbp), %eax
	cltq
	leaq	size_suffix(%rip), %rdx
	movzbl	(%rax,%rdx), %eax
	movsbl	%al, %ebx
	movq	-32(%rbp), %rax
	testq	%rax, %rax
	js	.L23
	pxor	%xmm5, %xmm5
	cvtsi2sdq	%rax, %xmm5
	movsd	%xmm5, -80(%rbp)
	jmp	.L24
.L23:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
	movsd	%xmm0, -80(%rbp)
.L24:
	movl	-20(%rbp), %edx
	movl	-24(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	power
	movsd	-80(%rbp), %xmm1
	divsd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	cvtsd2ss	%xmm1, %xmm0
	pxor	%xmm6, %xmm6
	cvtss2sd	%xmm0, %xmm6
	movq	%xmm6, %rdx
	movq	-40(%rbp), %rax
	movl	%ebx, %ecx
	movq	%rdx, %xmm0
	leaq	.LC6(%rip), %rdx
	movl	$2048, %esi
	movq	%rax, %rdi
	movl	$1, %eax
	call	snprintf@PLT
	movl	%eax, -44(%rbp)
	cmpl	$4, -44(%rbp)
	jg	.L25
	movq	-40(%rbp), %rax
	jmp	.L19
.L25:
	movl	-20(%rbp), %eax
	cltq
	leaq	size_suffix(%rip), %rdx
	movzbl	(%rax,%rdx), %eax
	movsbl	%al, %ebx
	movq	-32(%rbp), %rax
	testq	%rax, %rax
	js	.L26
	pxor	%xmm7, %xmm7
	cvtsi2sdq	%rax, %xmm7
	movsd	%xmm7, -80(%rbp)
	jmp	.L27
.L26:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
	movsd	%xmm0, -80(%rbp)
.L27:
	movl	-20(%rbp), %edx
	movl	-24(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	power
	movsd	-80(%rbp), %xmm1
	divsd	%xmm0, %xmm1
	cvttsd2siq	%xmm1, %rdx
	movq	-40(%rbp), %rax
	movl	%ebx, %r8d
	movq	%rdx, %rcx
	leaq	.LC7(%rip), %rdx
	movl	$2048, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf@PLT
	movl	%eax, -44(%rbp)
	cmpl	$4, -44(%rbp)
	jg	.L22
	movq	-40(%rbp), %rax
	jmp	.L19
.L22:
	addl	$1, -20(%rbp)
	jmp	.L28
.L14:
	cmpl	$0, -60(%rbp)
	je	.L29
	cmpl	$1, -60(%rbp)
	je	.L30
	jmp	.L37
.L29:
	movl	-24(%rbp), %eax
	movslq	%eax, %rcx
	movq	-32(%rbp), %rax
	movl	$0, %edx
	divq	%rcx
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rcx
	leaq	.LC8(%rip), %rdx
	movl	$2048, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf@PLT
	jmp	.L32
.L30:
	movq	-32(%rbp), %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rcx
	leaq	.LC8(%rip), %rdx
	movl	$2048, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf@PLT
	jmp	.L32
.L37:
	movq	-32(%rbp), %rax
	testq	%rax, %rax
	js	.L33
	pxor	%xmm2, %xmm2
	cvtsi2sdq	%rax, %xmm2
	movsd	%xmm2, -80(%rbp)
	jmp	.L34
.L33:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
	movsd	%xmm0, -80(%rbp)
.L34:
	movl	-60(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edx
	movl	-24(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	power
	movapd	%xmm0, %xmm1
	movsd	-80(%rbp), %xmm0
	divsd	%xmm1, %xmm0
	comisd	.LC9(%rip), %xmm0
	jnb	.L35
	cvttsd2siq	%xmm0, %rax
	jmp	.L36
.L35:
	movsd	.LC9(%rip), %xmm1
	subsd	%xmm1, %xmm0
	cvttsd2siq	%xmm0, %rax
	movabsq	$-9223372036854775808, %rdx
	xorq	%rdx, %rax
.L36:
	movq	-40(%rbp), %rdi
	movq	%rax, %rcx
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdx
	movl	$2048, %esi
	movl	$0, %eax
	call	snprintf@PLT
	nop
.L32:
	movq	-40(%rbp), %rax
.L19:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	pretty_size, .-pretty_size
	.section	.rodata
.LC10:
	.string	"/proc/meminfo"
	.align 8
.LC11:
	.string	"cannot find /proc/meminfo. Is /proc mounted?"
.LC12:
	.string	"open()"
.LC13:
	.string	"realloc()"
	.text
	.type	read_meminfo_file, @function
read_meminfo_file:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$248, %rsp
	.cfi_offset 3, -24
	movl	$0, %esi
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	open@PLT
	movl	%eax, -44(%rbp)
	cmpl	$-1, -44(%rbp)
	jne	.L39
	call	__errno_location@PLT
	movl	(%rax), %eax
	cmpl	$2, %eax
	jne	.L40
	leaq	.LC11(%rip), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	errx@PLT
.L40:
	leaq	.LC12(%rip), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	err@PLT
.L39:
	movl	$1, %esi
	movl	$1, %edi
	call	calloc@PLT
	movq	%rax, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L41
	leaq	.LC3(%rip), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	err@PLT
.L41:
	leaq	-256(%rbp), %rax
	movl	$200, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
	movq	$0, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -32(%rbp)
	jmp	.L42
.L46:
	cmpq	$200, -32(%rbp)
	ja	.L43
	movq	$800, -32(%rbp)
	movq	-40(%rbp), %rdx
	movq	-32(%rbp), %rax
	addq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L44
	leaq	.LC13(%rip), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	err@PLT
.L44:
	movq	-32(%rbp), %rax
	addq	%rax, -40(%rbp)
	jmp	.L45
.L43:
	subq	$200, -32(%rbp)
.L45:
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movq	-24(%rbp), %rdx
	addq	%rdx, %rax
	movq	-256(%rbp), %rcx
	movq	-248(%rbp), %rbx
	movq	%rcx, (%rax)
	movq	%rbx, 8(%rax)
	movq	-240(%rbp), %rcx
	movq	-232(%rbp), %rbx
	movq	%rcx, 16(%rax)
	movq	%rbx, 24(%rax)
	movq	-224(%rbp), %rcx
	movq	-216(%rbp), %rbx
	movq	%rcx, 32(%rax)
	movq	%rbx, 40(%rax)
	movq	-208(%rbp), %rcx
	movq	-200(%rbp), %rbx
	movq	%rcx, 48(%rax)
	movq	%rbx, 56(%rax)
	movq	-192(%rbp), %rcx
	movq	-184(%rbp), %rbx
	movq	%rcx, 64(%rax)
	movq	%rbx, 72(%rax)
	movq	-176(%rbp), %rcx
	movq	-168(%rbp), %rbx
	movq	%rcx, 80(%rax)
	movq	%rbx, 88(%rax)
	movq	-160(%rbp), %rcx
	movq	-152(%rbp), %rbx
	movq	%rcx, 96(%rax)
	movq	%rbx, 104(%rax)
	movq	-144(%rbp), %rcx
	movq	-136(%rbp), %rbx
	movq	%rcx, 112(%rax)
	movq	%rbx, 120(%rax)
	movq	-128(%rbp), %rcx
	movq	-120(%rbp), %rbx
	movq	%rcx, 128(%rax)
	movq	%rbx, 136(%rax)
	movq	-112(%rbp), %rcx
	movq	-104(%rbp), %rbx
	movq	%rcx, 144(%rax)
	movq	%rbx, 152(%rax)
	movq	-96(%rbp), %rcx
	movq	-88(%rbp), %rbx
	movq	%rcx, 160(%rax)
	movq	%rbx, 168(%rax)
	movq	-80(%rbp), %rcx
	movq	-72(%rbp), %rbx
	movq	%rcx, 176(%rax)
	movq	%rbx, 184(%rax)
	movq	-64(%rbp), %rdx
	movq	%rdx, 192(%rax)
	leaq	-256(%rbp), %rax
	movl	$199, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L42:
	leaq	-256(%rbp), %rcx
	movl	-44(%rbp), %eax
	movl	$199, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	testq	%rax, %rax
	jg	.L46
	movl	-44(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	read_meminfo_file, .-read_meminfo_file
	.section	.rodata
.LC14:
	.string	"strdup()"
	.align 8
.LC15:
	.string	"cannot get value of the provided key: '%s'"
.LC16:
	.string	" "
	.text
	.type	get_mem_kv, @function
get_mem_kv:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strdup@PLT
	movq	%rax, -16(%rbp)
	cmpq	$0, -16(%rbp)
	jne	.L49
	leaq	.LC14(%rip), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	err@PLT
.L49:
	movq	-48(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strstr@PLT
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L50
	movq	-48(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC15(%rip), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	errx@PLT
.L50:
	movq	-8(%rbp), %rax
	movl	$10, %esi
	movq	%rax, %rdi
	call	strchr@PLT
	subq	-8(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-8(%rbp), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
	jmp	.L51
.L52:
	addq	$1, -8(%rbp)
.L51:
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$32, %al
	jne	.L52
	jmp	.L53
.L54:
	addq	$1, -8(%rbp)
.L53:
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$32, %al
	je	.L54
	movq	-8(%rbp), %rax
	leaq	.LC16(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcspn@PLT
	movq	%rax, -24(%rbp)
	movq	-8(%rbp), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	conv_to_u64
	movq	%rax, -32(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movq	-32(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	get_mem_kv, .-get_mem_kv
	.section	.rodata
.LC17:
	.string	"MemTotal:"
.LC18:
	.string	"MemFree:"
.LC19:
	.string	"MemAvailable:"
.LC20:
	.string	"Shmem:"
.LC21:
	.string	"Buffers:"
.LC22:
	.string	"Cached:"
.LC23:
	.string	"SwapTotal:"
.LC24:
	.string	"SwapFree:"
	.text
	.type	do_collect_meminfo, @function
do_collect_meminfo:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	leaq	.LC17(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	get_mem_kv
	movq	-8(%rbp), %rdx
	movq	%rax, (%rdx)
	movq	-16(%rbp), %rax
	leaq	.LC18(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	get_mem_kv
	movq	-8(%rbp), %rdx
	movq	%rax, 8(%rdx)
	movq	-16(%rbp), %rax
	leaq	.LC19(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	get_mem_kv
	movq	-8(%rbp), %rdx
	movq	%rax, 16(%rdx)
	movq	-16(%rbp), %rax
	leaq	.LC20(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	get_mem_kv
	movq	-8(%rbp), %rdx
	movq	%rax, 24(%rdx)
	movq	-16(%rbp), %rax
	leaq	.LC21(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	get_mem_kv
	movq	-8(%rbp), %rdx
	movq	%rax, 32(%rdx)
	movq	-16(%rbp), %rax
	leaq	.LC22(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	get_mem_kv
	movq	-8(%rbp), %rdx
	movq	%rax, 40(%rdx)
	movq	-16(%rbp), %rax
	leaq	.LC23(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	get_mem_kv
	movq	-8(%rbp), %rdx
	movq	%rax, 48(%rdx)
	movq	-16(%rbp), %rax
	leaq	.LC24(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	get_mem_kv
	movq	-8(%rbp), %rdx
	movq	%rax, 56(%rdx)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	do_collect_meminfo, .-do_collect_meminfo
	.section	.rodata
.LC25:
	.string	"%s\n"
	.text
	.type	print_collected_info, @function
print_collected_info:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	subq	%rax, %rdx
	movq	%rdx, -8(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movl	$1, %ecx
	movl	$0, %edx
	movl	$1, %esi
	movq	%rax, %rdi
	call	pretty_size
	movq	%rax, %rdx
	movq	stdout(%rip), %rax
	leaq	.LC25(%rip), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movq	-8(%rbp), %rax
	movl	$1, %ecx
	movl	$0, %edx
	movl	$1, %esi
	movq	%rax, %rdi
	call	pretty_size
	movq	%rax, %rdx
	movq	stdout(%rip), %rax
	leaq	.LC25(%rip), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movl	$1, %ecx
	movl	$0, %edx
	movl	$1, %esi
	movq	%rax, %rdi
	call	pretty_size
	movq	%rax, %rdx
	movq	stdout(%rip), %rax
	leaq	.LC25(%rip), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movq	-24(%rbp), %rax
	movq	24(%rax), %rax
	movl	$1, %ecx
	movl	$0, %edx
	movl	$1, %esi
	movq	%rax, %rdi
	call	pretty_size
	movq	%rax, %rdx
	movq	stdout(%rip), %rax
	leaq	.LC25(%rip), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	print_collected_info, .-print_collected_info
	.globl	main
	.type	main, @function
main:
.LFB13:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	call	read_meminfo_file
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	do_collect_meminfo
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	print_collected_info
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC2:
	.long	0
	.long	1072693248
	.align 8
.LC9:
	.long	0
	.long	1138753536
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
