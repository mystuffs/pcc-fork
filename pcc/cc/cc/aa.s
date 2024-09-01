	.file "aa.c"
	.section .text
	.align 4
	.globl main
	.type main,@function
main:
	pushq %rbp
	movq %rsp,%rbp
.L449:
.L453:
	movabs $.L455,%rsi
	movq stdout(%rip),%rdi
	xorl %eax,%eax
	call fprintf
.L451:
	leave
	ret
	.size main,.-main
	.section        .note.GNU-stack,"",@progbits
	.section .rodata
.L455:
	.ascii "Hello world\012\0"
	.ident "PCC: Portable C Compiler 1.2.0.DEVEL 20231021 for x86_64-pc-linux-gnu"
	.end
