	.section .bss
_a:
	.zero	4
	.align	4
_c:
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
	.string	"test:%d\n"
	.align	4

	.section .text
	.globl main

main:
	pushl $_a
	pushl $STR0
	call scanf
	addl $8, %esp
	movl _a, %eax
	imul $-1, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t1
	movl %eax, _c
	pushl _c
	pushl $STR1
	call printf
	addl $8, %esp

	ret
