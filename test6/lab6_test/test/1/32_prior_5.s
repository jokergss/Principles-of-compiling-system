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
t2:
	.zero	4
	.align	4
t3:
	.zero	4
	.align	4
t4:
	.zero	4
	.align	4
t5:
	.zero	4
	.align	4
t6:
	.zero	4
	.align	4
t7:
	.zero	4
	.align	4
t8:
	.zero	4
	.align	4
t9:
	.zero	4
	.align	4

	.section .rodata
STR0:
	.string	"%d\n"
	.align	4

	.section .text
	.globl main

main:
	movl $2, %eax
	imul $-1, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t0
	movl %eax, _a
	movl $1, %eax
	movl %eax, t1
	movl %eax, _b
	movl _b, %eax
	imul $-1, %eax
	movl %eax, t0
	movl _a, %eax
	subl t0, %eax
	movl %eax, t4
	movl _a, %eax
	addl _b, %eax
	movl %eax, t8
	movl t8, %eax
	imul $-1, %eax
	movl %eax, t7
	movl _a, %eax
	subl _b, %eax
	movl %eax, t9
	movl t9, %eax
	imul $-1, %eax
	movl %eax, t0
	XOR %edx, %edx
	movl t7, %eax
	cmp %edx, %eax
	jge O0
	movl $0, %edx
	not %edx
O0:
	movl t0, %ebx
	idiv %ebx
	XOR %eax, %eax
	movl %edx, t0
	movl t4, %eax
	addl t0, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t2
	movl %eax, _a
	pushl _a
	pushl $STR0
	call printf
	addl $8, %esp

	ret
