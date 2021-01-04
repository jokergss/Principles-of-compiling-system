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
_result:
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
t16:
	.zero	4
	.align	4
t17:
	.zero	4
	.align	4
t18:
	.zero	4
	.align	4
t19:
	.zero	4
	.align	4
t20:
	.zero	4
	.align	4
t21:
	.zero	4
	.align	4
t22:
	.zero	4
	.align	4
t23:
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
	movl $5, %eax
	movl %eax, t0
	movl %eax, _a
	movl $5, %eax
	movl %eax, t1
	movl %eax, _b
	movl $1, %eax
	movl %eax, t2
	movl %eax, _c
	movl $2, %eax
	imul $-1, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t3
	movl %eax, _d
	movl $2, %eax
	movl %eax, t4
	movl %eax, _result
	movl _d, %eax
	imull $1, %eax
	movl %eax, t8
	XOR %edx, %edx
	movl t8, %eax
	cmp %edx, %eax
	jge O0
	movl $0, %edx
	not %edx
O0:
	movl $2, %ebx
	idiv %ebx
	XOR %edx, %edx
	movl %eax, t7
	movl t7, %eax
	cmp $0, %eax
	jl label0
	jmp label2
label2:
	movl _a, %eax
	subl _b, %eax
	movl %eax, t11
	movl t11, %eax
	cmp $0, %eax
	jne label3
	jmp label1
label3:
	movl _c, %eax
	addl $3, %eax
	movl %eax, t13
	XOR %edx, %edx
	movl t13, %eax
	cmp %edx, %eax
	jge O1
	movl $0, %edx
	not %edx
O1:
	movl $2, %ebx
	idiv %ebx
	XOR %eax, %eax
	movl %edx, t12
	movl t12, %eax
	cmp $0, %eax
	jne label0
	jmp label1
label0:
	pushl _result
	pushl $STR0
	call printf
	addl $8, %esp

label1:
	XOR %edx, %edx
	movl _d, %eax
	cmp %edx, %eax
	jge O2
	movl $0, %edx
	not %edx
O2:
	movl $2, %ebx
	idiv %ebx
	XOR %eax, %eax
	movl %edx, t17
	movl t17, %eax
	addl $67, %eax
	movl %eax, t16
	movl t16, %eax
	cmp $0, %eax
	jl label4
	jmp label6
label6:
	movl _a, %eax
	subl _b, %eax
	movl %eax, t20
	movl t20, %eax
	cmp $0, %eax
	jne label7
	jmp label5
label7:
	movl _c, %eax
	addl $2, %eax
	movl %eax, t22
	XOR %edx, %edx
	movl t22, %eax
	cmp %edx, %eax
	jge O3
	movl $0, %edx
	not %edx
O3:
	movl $2, %ebx
	idiv %ebx
	XOR %eax, %eax
	movl %edx, t21
	movl t21, %eax
	cmp $0, %eax
	jne label4
	jmp label5
label4:
	movl $4, %eax
	movl %eax, t23
	movl %eax, _result
	pushl _result
	pushl $STR1
	call printf
	addl $8, %esp

label5:

	ret
