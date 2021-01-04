	.section .bss
_b:
	.zero	4
	.align	4
t0:
	.zero	4
	.align	4

	.section .rodata

	.section .text
	.globl main

main:
	movl _a, %eax
	addl _c, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t0
	movl %eax, _b

	ret
