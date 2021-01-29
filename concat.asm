section .text
global concat
concat:
    lea eax, [rdi]
    lea ebx, [rsi]

    lea rsi, [eax]
    call loop_copy
    mov rdi, rax

    lea rsi, [ebx]
    call loop_copy

    ret

loop_copy:
    movsb
    cmp byte [rdi-1], 0
    je copy_to_rax
    jmp loop_copy
copy_to_rax:
    lea rax, [rdi-1]
    ret
