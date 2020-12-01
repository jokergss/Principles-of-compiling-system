    .section  .data
    .globl num1
    .globl num2
    .globl times
    .align 4
    .size num1 , 4
    .size num2 , 4
    .size times , 4

num1:
    .zero 4
    .align 4

num2:
    .long 1
    .align 4
    
times:
    .long 1
    .comm temp ,4
    .comm n ,4
    .section .rodata

str1:
    .string "%d "

    .text
    .globl main
    .type main, @function

main:
    movl num1 , %eax
    pushl %eax
    pushl $str1
    call printf
    addl $8 , %esp

    movl num2 , %eax
    pushl %eax
    pushl $str1
    call printf
    addl $8 , %esp 

    jmp L2

L3:
    movl num2 , %eax
    movl %eax , temp

    movl num1 , %edx
    movl num2 , %eax
    addl %edx , %eax
    movl %eax , num2

    movl num2 , %eax
    pushl %eax
    pushl $str1
    call printf
    addl $8 , %esp 

    movl temp , %eax
    movl %eax , num1

    movl times , %eax
    addl $1 , %eax
    movl %eax , times

L2:
    movl times , %eax
    cmpl $10 , %eax
    jl L3
    movl $0 ,%eax
    ret

.section  .note.GNU-stack,"",@progbits
