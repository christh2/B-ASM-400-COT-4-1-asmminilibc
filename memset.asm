; memset : void *memset(void *s, int c, size_t n);
BITS 64
global memset:

section .text

memset:
    xor     rax, rax       ; pour stocker l'adresse de destination
    xor     rcx, rcx       ; compteur pour le nombre d'octets remplis
    jmp     loop

loop:
    cmp     rdx, 0         ; Compare le nombre d'octets restants (n) a 0
    je      end            ; si n!=0, fin

    mov     byte [rdi + rcx], sil  ; c dans la mémoire à l'adresse [rdi + rcx]
    dec     rdx             ; Déc le nombre d'octets restants (n)
    inc     rcx             ; Inc le compteur pour suivre le nombre d'octets remplis
    jmp     loop

end:
    mov     rax, rdi        ; l'adresse de destination dans rax
    ret
