	.section .bss
_a:
	.zero	4
	.align	4
_b:
	.zero	4
	.align	4
t0:
	.zero	4
	.align	4
t1:
	.zero	4
	.align	4

	.section .rodata
STR0:
	.string	"%d"
	.align	4
STR1:
	.string	"%d"
	.align	4

	.section .text
	.globl main

main:
	movl $3, %eax
	movl %eax, t1
	movl %eax, _b
	movl t1, %eax
	movl %eax, t0
	movl %eax, _a
	pushl _a
	pushl $STR0
	call printf
	addl $8, %esp
	pushl _b
	pushl $STR1
	call printf
	addl $8, %esp

	ret
