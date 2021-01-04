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
t0:
	.zero	4
	.align	4
t1:
	.zero	4
	.align	4
t2:
	.zero	4
	.align	4

	.section .rodata
STR0:
	.string	"%d"
	.align	4
STR1:
	.string	"%d"
	.align	4
STR2:
	.string	"test:%d\n"
	.align	4

	.section .text
	.globl main

main:
	pushl $_a
	pushl $STR0
	call scanf
	addl $8, %esp
	pushl $_b
	pushl $STR1
	call scanf
	addl $8, %esp
	movl _a, %eax
	subl _b, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t2
	movl %eax, _c
	pushl _c
	pushl $STR2
	call printf
	addl $8, %esp

	ret
