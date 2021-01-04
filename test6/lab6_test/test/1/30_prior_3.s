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
_t:
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

	.section .rodata
STR0:
	.string	"%d\n"
	.align	4
STR1:
	.string	"%d\n"
	.align	4

	.section .text
	.globl main

main:
	movl $1, %eax
	movl %eax, t0
	movl %eax, _a
	movl $4, %eax
	movl %eax, t1
	movl %eax, _b
	movl $28, %eax
	movl %eax, t2
	movl %eax, _c
	movl _c, %eax
	addl _a, %eax
	movl %eax, t3
	movl t3, %eax
	cmp _b, %eax
	jne label0
	jmp label1
label0:
	movl _b, %eax
	imul $-1, %eax
	movl %eax, t0
	XOR %edx, %edx
	movl _c, %eax
	cmp %edx, %eax
	jge O0
	movl $0, %edx
	not %edx
O0:
	movl t0, %ebx
	idiv %ebx
	XOR %eax, %eax
	movl %edx, t0
	movl t0, %eax
	movl %eax, t4
	movl %eax, _t
	pushl _t
	pushl $STR0
	call printf
	addl $8, %esp

label1:
	movl _b, %eax
	subl _c, %eax
	movl %eax, t6
	movl t6, %eax
	cmp _a, %eax
	je label2
	jmp label3
label2:
	XOR %edx, %edx
	movl _c, %eax
	cmp %edx, %eax
	jge O1
	movl $0, %edx
	not %edx
O1:
	movl _b, %ebx
	idiv %ebx
	XOR %eax, %eax
	movl %edx, t8
	movl t8, %eax
	addl _b, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t7
	movl %eax, _t
	pushl _t
	pushl $STR1
	call printf
	addl $8, %esp

label3:

	ret
