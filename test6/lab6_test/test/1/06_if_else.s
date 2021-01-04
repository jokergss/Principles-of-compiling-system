	.section .bss
_a:
	.zero	4
	.align	4
t0:
	.zero	4
	.align	4

	.section .rodata
STR0:
	.string	"test:%d\n"
	.align	4

	.section .text
	.globl main

main:
	movl $10, %eax
	movl %eax, t0
	movl %eax, _a
	movl _a, %eax
	cmp $9, %eax
	jg label0
	jmp label2
label0:
	movl _a, %eax
	subl $20, %eax
	movl %eax, t0
	movl %eax, _a

	JMP label1
label2:
	movl _a, %eax
	addl $15, %eax
	movl %eax, t0
	movl %eax, _a

label1:
	pushl _a
	pushl $STR0
	call printf
	addl $8, %esp

	ret
