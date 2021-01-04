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

	.section .rodata
STR0:
	.string	"%d"
	.align	4
STR1:
	.string	"%d"
	.align	4
STR2:
	.string	"Success\n"
	.align	4
STR3:
	.string	"Failed\n"
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
	cmp _b, %eax
	je label0
	jmp label2
label0:
	pushl $STR2
	call printf
	addl $4, %esp

	JMP label1
label2:
	pushl $STR3
	call printf
	addl $4, %esp

label1:

	ret
