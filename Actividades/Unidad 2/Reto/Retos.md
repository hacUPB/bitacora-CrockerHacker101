### **2**
``` 
int sum = 0;

for(int i = 1; i <= 100; i++) {
    sum += i;
}
```

### **3**
```
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
```

### **4**

***como se declara un puntero en c++*** 
int *punt;

***Como se define (o inicializa) un puntero en C++?***
punt  = &var; 

***¿Cómo se almacena en C++ la dirección de memoria de una variable?***
punt = &var; 

***¿Cómo se escribe el contenido de la variable a la que apunta un puntero?***
*punt = 20; 


### **6-7**: Traducción:  
```
@10  
D=A
@16
M=D
@5
D=A
@17
M=D
@16
D=A
@18
M=D
@18
A=M
D=M
@17
M=D
```

### **8**: ¿Qué es cada cosa?  

** int pvar; **: esto es para declarar una variable pero sin declarar un lugar.  
** pvar = var; **: esta declaración esta incorrecta e imcompleta, ya que, necesita un "&" para asignarle el lugar de la variable dicha.  
** var2 = *pvar; **: esto asigna una variable en el valor del puntero dicho, el "*" es para acceder al contenido de la variable, y esta tomara el valor de var2.  
** pvar = &var3; **: "&" este signo es para declarar la dirección de memoria de var3  

### **9**: Una posible solución:  
```
@6
D=A
@0
D=M
@9
D=A
@1
D=M
@0
D=M
@1
D=D+M
@2
M=D
(END)
END
0;JMP
```
