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
t2:
	.zero	4
	.align	4
t3:
	.zero	4
	.align	4
t4:
	.zero	4
	.align	4

	.section .rodata
STR0:
	.string	"Test:%d\n"
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
	subl $10, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t1
	movl %eax, _a
	XOR %edx, %edx
	movl _a, %eax
	cmp %edx, %eax
	jge O0
	movl $0, %edx
	not %edx
O0:
	movl $6, %ebx
	idiv %ebx
	XOR %eax, %eax
	movl %edx, t0
	movl t0, %eax
	movl %eax, t2
	movl %eax, _a

	JMP label1
label2:
	movl $2, %eax
	movl %eax, t3
	movl %eax, _a
	movl _a, %eax
	subl $30, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t4
	movl %eax, _a

label1:
	pushl _a
	pushl $STR0
	call printf
	addl $8, %esp

	ret
