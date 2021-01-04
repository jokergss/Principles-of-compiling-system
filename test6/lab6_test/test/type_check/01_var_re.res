	.section .bss
_a:
	.zero	4
	.align	4
_a:
	.zero	4
	.align	4
t0:
	.zero	4
	.align	4
t1:
	.zero	4
	.align	4

	.section .rodata

	.section .text
	.globl main

main:
	movl $10, %eax
	movl %eax, t0
	movl %eax, _a
	movl $20, %eax
	movl %eax, t1
	movl %eax, _a

	ret
