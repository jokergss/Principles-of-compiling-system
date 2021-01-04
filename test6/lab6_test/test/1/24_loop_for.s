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
	.string	"In Loop\n"
	.align	4
STR1:
	.string	"End Loop\n"
	.align	4

	.section .text
	.globl main

main:
	movl $0, %eax
	movl %eax, t0
	movl %eax, _a
label0:
	movl _a, %eax
	cmp $200, %eax
	jl label1
	jmp label2
label1:
	pushl $STR0
	call printf
	addl $4, %esp

	movl _a, %eax
	addl $1, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t1
	movl %eax, _a
	JMP label0
label2:
	pushl $STR1
	call printf
	addl $4, %esp

	ret
