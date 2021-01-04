	.section .bss
_a:
	.zero	4
	.align	4
t0:
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
	pushl _a
	pushl $STR1
	call printf
	addl $8, %esp

	ret
