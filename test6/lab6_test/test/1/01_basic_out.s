	.section .bss

	.section .rodata
STR0:
	.string	"test\n"
	.align	4

	.section .text
	.globl main

main:
	pushl $STR0
	call printf
	addl $4, %esp

	ret
