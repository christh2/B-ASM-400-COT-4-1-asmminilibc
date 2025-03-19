BITS 64
section .text
global strncmp

strncmp:
    xor rax, rax
    xor rcx, rcx
    mov rcx, rdx        ;longueur maximale dans rcx
    jmp section1

section1:
    mov al, byte [rdi]
    mov dl, byte [rsi]
    cmp rcx, 0
    je end
    cmp al, dl
    jne not_equal       ; Saute si les caractères sont différents
    cmp al, 0           ; Compare le caractère avec zéro
    je end
    inc rdi
    inc rsi
    dec rcx
    jmp section1

not_equal:
    movsx rax, al       ; permet de quitté 8 bits pour 64
    movsx rdi, dl
    sub rax, rdi        ; la différence
    ret                 ;

end:
    xor rax, rax
    ret