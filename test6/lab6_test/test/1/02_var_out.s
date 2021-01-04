	.section .bss
_a:
	.zero	4
	.align	4
t0:
	.zero	4
	.align	4

	.section .rodata
STR0:
	.string	"test:%d\n"
	.align	4

	.section .text
	.globl main

main:
	movl $10, %eax
	movl %eax, t0
	movl %eax, _a
	pushl _a
	pushl $STR0
	call printf
	addl $8, %esp

	ret
