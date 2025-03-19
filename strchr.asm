BITS 64
global strchr

section .text
; strchr : char *strchr(const char *str, int c);

strchr:
    xor     rax, rax
    cmp     sil, 0
    je      null_char
    jmp     loop

loop:
    mov     r10b, byte [rdi]
    cmp     r10b, 0
    je      end_null
    cmp     r10b, sil
    je      end
    add     rdi, 1
    jmp     loop

null_char:
    cmp     byte [rdi], 0
    je      end
    inc     rdi
    jmp     null_char

end:
    mov     rax, rdi    ;adrs du caractère trouvé dans rax
    ret

end_null:
    ret
