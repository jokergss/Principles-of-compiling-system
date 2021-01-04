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
	movl $0, %eax
	movl %eax, t0
	movl %eax, _a
	movl $0, %eax
	movl %eax, t1
	movl %eax, _b
label0:
	movl _a, %eax
	cmp $100, %eax
	jl label1
	jmp label2
label1:
	movl _a, %eax
	cmp $5, %eax
	je label3
	jmp label5
label3:
	movl $25, %eax
	movl %eax, t2
	movl %eax, _b

	JMP label4
label5:
	movl _a, %eax
	cmp $10, %eax
	je label6
	jmp label7
label6:
	movl $42, %eax
	movl %eax, t3
	movl %eax, _b

	JMP label4
label7:
	movl _a, %eax
	imull $2, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t4
	movl %eax, _b

label4:
label4:
	movl _a, %eax
	addl $1, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t5
	movl %eax, _a

	jmp label0
label2:
	pushl _a
	pushl $STR0
	call printf
	addl $8, %esp
	pushl _b
	pushl $STR1
	call printf
	addl $8, %esp

	ret
