	.section .bss
_s:
	.zero	4
	.align	4
_t:
	.zero	4
	.align	4
_a:
	.zero	4
	.align	4
_r:
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
	.string	"9"
	.align	4
STR1:
	.string	"\t"
	.align	4
STR2:
	.string	"t"
	.align	4
STR3:
	.string	"\n"
	.align	4
STR4:
	.string	"a"
	.align	4
STR5:
	.string	"%c"
	.align	4
STR6:
	.string	"%c"
	.align	4
STR7:
	.string	"%c"
	.align	4
STR8:
	.string	"%c"
	.align	4
STR9:
	.string	"%c"
	.align	4

	.section .text
	.globl main

main:
	movl STR0, %eax
	movl %eax, t0
	movl %eax, _s
	movl STR1, %eax
	movl %eax, t1
	movl %eax, _t
	movl STR2, %eax
	movl %eax, t2
	movl %eax, _a
	movl STR3, %eax
	movl %eax, t3
	movl %eax, _r
	movl STR4, %eax
	movl %eax, t4
	movl %eax, _t
	pushl _s
	pushl $STR5
	call printf
	addl $8, %esp
	pushl _t
	pushl $STR6
	call printf
	addl $8, %esp
	pushl _a
	pushl $STR7
	call printf
	addl $8, %esp
	pushl _r
	pushl $STR8
	call printf
	addl $8, %esp
	pushl _t
	pushl $STR9
	call printf
	addl $8, %esp

	ret
