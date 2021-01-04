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
	.string	"%d"
	.align	4
STR1:
	.string	"In Loop\n"
	.align	4
STR2:
	.string	"End Loop\n"
	.align	4

	.section .text
	.globl main

main:
	pushl $_a
	pushl $STR0
	call scanf
	addl $8, %esp
label0:
	movl _a, %eax
	cmp $0, %eax
	jg label1
	jmp label2
label1:
	movl _a, %eax
	subl $1, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t1
	movl %eax, _a
	pushl $STR1
	call printf
	addl $4, %esp

	jmp label0
label2:
	pushl $STR2
	call printf
	addl $4, %esp

	ret
