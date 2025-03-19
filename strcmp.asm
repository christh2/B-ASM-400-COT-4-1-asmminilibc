BITS 64
section .text
global strcmp

strcmp:
    xor rax, rax
    jmp section1

section1:
    mov al, byte [rdi]
    mov dl, byte [rsi]
    cmp al, dl
    jne not_equal
    cmp al, 0
    je end
    inc rdi
    inc rsi

    jmp section1

not_equal:
    movsx rax, al
    movsx rdi, dl
    sub rax, rdx
    ret

end:
    xor rax, rax
    ret