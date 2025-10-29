section .data
sum dd 0
limit dd 100

section .text
global _start

_start:
mov eax,0        ; sum = 0
mov ecx,1        ; i = 1

for_loop:
cmp ecx,[limit]  ; i <= 100 ?
jg end_for       ; si i > 100 salir
add eax,ecx      ; sum += i
inc ecx          ; i++
jmp for_loop

end_for:
mov [sum],eax    ; guardar el resultado final en sum

mov eax,1        ; sys_exit
mov ebx,0
int 0x80