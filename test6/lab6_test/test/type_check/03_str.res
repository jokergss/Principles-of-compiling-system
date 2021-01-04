	.section .bss
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
STR0:
	.string	"0"
	.align	4
STR1:
	.string	"0"
	.align	4

	.section .text
	.globl main

main:
	movl $10, %eax
	addl $0, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t0
	movl %eax, _a
	movl $10, %eax
	addl $0, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t1
	movl %eax, _a

	ret
