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
t2:
	.zero	4
	.align	4
t3:
	.zero	4
	.align	4

	.section .rodata

	.section .text
	.globl main

main:
	movl $10, %eax
	movl %eax, t0
	movl %eax, _b
	movl $4, %eax
	movl %eax, t1
	movl %eax, _a
	movl $5, %eax
	movl %eax, t2
	movl %eax, _b
	movl _a, %eax
	addl $1, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t3
	movl %eax, _a

	ret
