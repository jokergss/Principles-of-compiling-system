	.section .bss
_a:
	.zero	4
	.align	4
_b:
	.zero	4
	.align	4
_c:
	.zero	4
	.align	4
_d:
	.zero	4
	.align	4
t0:
	.zero	4
	.align	4
t1:
	.zero	4
	.align	4
t2:
	.zero	4
	.align	4
t3:
	.zero	4
	.align	4
t4:
	.zero	4
	.align	4

	.section .rodata
STR0:
	.string	"%d\n"
	.align	4

	.section .text
	.globl main

main:
	movl $16, %eax
	movl %eax, t0
	movl %eax, _a
	movl $2, %eax
	movl %eax, t1
	movl %eax, _b
	movl $30, %eax
	movl %eax, t2
	movl %eax, _c
	movl _b, %eax
	imull _c, %eax
	movl %eax, t0
	movl _a, %eax
	addl t0, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t3
	movl %eax, _d
	pushl _d
	pushl $STR0
	call printf
	addl $8, %esp

	ret
