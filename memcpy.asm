BITS 64
section .text
global memcpy

memcpy:
    mov rax, rdi        ; adr dest dans rax
    mov rcx, rdx        ; taill  dans rcx
    jmp section1

section1:
    cmp rcx, 0
    je end
    mov al, byte [rsi]  ; source pointée par rsi dans al
    mov byte [rdi], al  ; octet de la source a dest
    inc rsi
    inc rdi
    dec rcx             ; nombre d'octets restants
    jmp section1

end:
    ret
