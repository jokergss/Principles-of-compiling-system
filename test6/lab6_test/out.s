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

	.section .rodata
STR0:
	.string	"test:%d %d\n"
	.align	4

	.section .text
	.globl main

main:
	movl $100020, %eax
	imul $-1, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t0
	movl %eax, _a
	movl $3, %eax
	imul $-1, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t1
	movl %eax, _b
	XOR %edx, %edx
	movl _a, %eax
	cmp %edx, %eax
	jge O0
	movl $0, %edx
	not %edx
O0:
	movl _b, %ebx
	idiv %ebx
	XOR %edx, %edx
	movl %eax, t0
	movl t0, %eax
	movl %eax, t2
	movl %eax, _c
	XOR %edx, %edx
	movl _a, %eax
	cmp %edx, %eax
	jge O1
	movl $0, %edx
	not %edx
O1:
	movl _b, %ebx
	idiv %ebx
	XOR %eax, %eax
	movl %edx, t0
	movl t0, %eax
	movl %eax, t3
	movl %eax, _d
	pushl _d
	pushl _c
	pushl $STR0
	call printf
	addl $12, %esp

	ret
