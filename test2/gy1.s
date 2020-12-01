    .data
    .globl num
    .globl temp
    .align 4
    .size num ,4
    .size temp , 4
num:
    .long 1
    .align 4
temp:
    .long 1
    .align 4
    .comm a ,4
    .section  .rodata
STR0:
    .string "%d"
STR1:
    .string "result:%d"

    .text
    .globl main
    .type main,@function
main:
    pushl $a
    pushl $STR0
    call scanf
    addl $8 , %esp

    jmp L2

L3:
    movl num , %edx
    movl temp ,%eax
    imull %edx ,%eax
    movl %eax ,num
    movl temp , %eax
    addl $1 , %eax
    movl %eax , temp

L2:
    movl temp , %edx
    movl a , %eax
    cmpl %eax , %edx
    jle L3

    movl num , %eax
    pushl %eax
    pushl $STR1
    call printf
    addl $8 , %esp

    movl $0 ,%eax
    ret
    .section .note.GNU-stack,"",@progbits
