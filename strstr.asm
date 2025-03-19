; strstr: char *strstr(const char *haystack, const char *needle);
BITS 64

global strstr:

SECTION .text

strstr:
    xor     rax, rax
    cmp     BYTE [rsi], 0         ; prmier caratere de needle a 0
    je      end

    jmp     loop

check_for_str:
    mov     r11b, BYTE [rsi + rbx] ; byte suivant de needle r11b
    cmp     r11b, 0
    je      end
    cmp     r11b, BYTE [rdi + rcx] ; byte de needle et byte de haystack
    jne     increment
    inc     rbx                   ; byte de needle
    inc     rcx                   ; byte  de haystack
    jmp     check_for_str

increment:
    inc     rdi                   ; byte suivant de haystack
    jmp     loop

loop:
    mov     r10b, BYTE [rdi]       ; byte suivant de haystack r10b
    cmp     r10b, 0
    je      end_null

    xor     rbx, rbx              ; our parcourir needle
    xor     rcx, rcx              ; pour parcourir haystack
    cmp     r10b, BYTE [rsi]      ; byte de haystack avec le premier byte de needle
    je      check_for_str

    add     rdi, 1                ; suivant de haystack
    jmp     loop

end_null:
    ret                           ; fin

end:
    mov     rax, rdi              ; le pointeur sur le résultat (sous-chaîne trouvée)
    ret