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
_d:
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
	.string	"%d"
	.align	4

	.section .text
	.globl main

main:
	movl $20, %eax
	movl %eax, t0
	movl %eax, _a
	movl $5, %eax
	movl %eax, t1
	movl %eax, _b
	movl $6, %eax
	movl %eax, t2
	movl %eax, _c
	movl $4, %eax
	imul $-1, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t3
	movl %eax, _d
	movl _c, %eax
	imull _d, %eax
	movl %eax, t0
	movl _a, %eax
	addl t0, %eax
	movl %eax, t6
	movl _a, %eax
	addl _d, %eax
	movl %eax, t0
	XOR %edx, %edx
	movl _b, %eax
	cmp %edx, %eax
	jge O0
	movl $0, %edx
	not %edx
O0:
	movl t0, %ebx
	idiv %ebx
	XOR %eax, %eax
	movl %edx, t8
	XOR %edx, %edx
	movl t8, %eax
	cmp %edx, %eax
	jge O1
	movl $0, %edx
	not %edx
O1:
	movl _a, %ebx
	idiv %ebx
	XOR %edx, %edx
	movl %eax, t0
	movl t6, %eax
	subl t0, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t4
	movl %eax, _a
	pushl _a
	pushl $STR0
	call printf
	addl $8, %esp

	ret
