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
t9:
	.zero	4
	.align	4
t10:
	.zero	4
	.align	4
t11:
	.zero	4
	.align	4
t12:
	.zero	4
	.align	4
t13:
	.zero	4
	.align	4
t14:
	.zero	4
	.align	4
t15:
	.zero	4
	.align	4

	.section .rodata
STR0:
	.string	"%d"
	.align	4

	.section .text
	.globl main

main:
	movl $3, %eax
	movl %eax, t0
	movl %eax, _a
	movl $8, %eax
	movl %eax, t1
	movl %eax, _b
	movl $4, %eax
	imul $-1, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t2
	movl %eax, _c
	movl $15, %eax
	movl %eax, t3
	movl %eax, _d
	movl _b, %eax
	subl _a, %eax
	movl %eax, t0
	XOR %edx, %edx
	movl _d, %eax
	cmp %edx, %eax
	jge O0
	movl $0, %edx
	not %edx
O0:
	movl t0, %ebx
	idiv %ebx
	XOR %eax, %eax
	movl %edx, t6
	movl t6, %eax
	cmp $0, %eax
	jne label2
	jmp label1
label2:
	movl _a, %eax
	cmp $0, %eax
	jg label0
	jmp label3
label3:
	XOR %edx, %edx
	movl _d, %eax
	cmp %edx, %eax
	jge O1
	movl $0, %edx
	not %edx
O1:
	movl $3, %ebx
	idiv %ebx
	XOR %eax, %eax
	movl %edx, t12
	movl t12, %eax
	cmp $0, %eax
	je label4
	jmp label1
label4:
	movl _c, %eax
	cmp $0, %eax
	jg label0
	jmp label1
label0:
	movl _d, %eax
	addl _c, %eax
	movl %eax, t15
	movl _b, %eax
	imul $-1, %eax
	movl %eax, t0
	movl t15, %eax
	subl t0, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t13
	movl %eax, _t
	pushl _t
	pushl $STR0
	call printf
	addl $8, %esp

label1:

	ret
