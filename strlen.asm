BITS 64

section .text
global strlen

strlen:
        xor rax, rax
        jmp section1

section1:
    cmp byte[rdi + rax], 0
    je end
    inc rax
    jmp section1

end:
    ret
