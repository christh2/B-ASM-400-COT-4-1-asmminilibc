BITS 64
section .text
global strrchr

strrchr:
    xor rcx, rcx
    jmp strlen                 ; longueur de la chaîne (rcx = strlen(rdi))

decrement:
    dec rcx                    ; Décrémente rcx

loop:
    mov al, byte [rdi + rcx]
    cmp al, 0
    je null
    cmp al, sil
    jne decrement

    lea rax, [rdi + rcx]       ;adresse du dernier caractère trouvé (rdi + rcx) 'p19kof'
    ret

null:
    xor rax, rax
    ret

incrementStrlen:               ; longueur de la chaîne
    inc rcx

strlen:
    cmp byte [rdi + rcx], 0
    jne incrementStrlen
    dec rcx                    ; Dec rcx de 1 pour obtenir la longueur correcte
    jmp loop
