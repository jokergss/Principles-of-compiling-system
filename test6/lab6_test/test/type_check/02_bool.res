	.section .bss
_a:
	.zero	4
	.align	4
t0:
	.zero	4
	.align	4

	.section .rodata

	.section .text
	.globl main

main:
	movl $10, %eax
	movl %eax, t0
	movl %eax, _a
	movl _a, %eax
	addl $2, %eax
	movl %eax, t0
label0:
	movl _a, %eax
	subl $2, %eax
	movl %eax, t0
	movl %eax, _a

label1:

	ret
