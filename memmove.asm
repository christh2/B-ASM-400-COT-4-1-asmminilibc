; const void *memmove(void *dest, void *src, size_t n);
BITS 64

global memmove

section .text

memmove:
    mov rcx, 0
    jmp check

loop:
    mov bl, byte [rsi + rcx]    ; Copie de ptr[i] vers al (registre 8 bit low)
    mov byte [rdi + rcx], bl    ; Copie de al vers ptr2[i]
    inc rcx

check:
    cmp rdx, rcx                ; if (i < n)
    jg loop                     ; branchement à l’adresse si op1 > op2
    mov rax, rdi                ; return ptr
    ret
