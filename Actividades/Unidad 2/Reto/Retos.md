# Reto 2  

### 1:
```asm
@i
M=1
@sum
M=0
(LOOP)
@i
D=M
@101
D=D-A
@END
D;JGE
@i
D=M
@sum
M=D+M
@i
M=M+1
@LOOP
0;JMP
(END)
@END
0;JMP
```
- 1. ¿Cómo están implementadas las variables i y sum?
Las variables i y sum están implementadas como símbolos. El lenguaje Hack no tiene variables como tal, pero el ensamblador asigna automáticamente a cada símbolo una dirección de memoria RAM empezando desde RAM[16].

- 2. ¿En qué direcciones de memoria están estas variables?
´i → RAM[16]´
´sum → RAM[17]´

- 3. ¿Cómo está implementado el ciclo while?
El ciclo while (i <= 100) se traduce en etiquetas y saltos condicionales:  

(LOOP) marca el comienzo del ciclo.  
Se evalúa la condición i <= 100 haciendo i - 101 y saltando si el resultado es mayor o igual a 0.  
@END con D;JGE termina el ciclo.  
@LOOP con 0;JMP vuelve al inicio del ciclo.   

- 4. ¿Cómo se implementa la variable i?  
Se implementa usando memoria RAM. Por ejemplo:  
```
@i
M=M+1 
```
Esto accede a la dirección asociada al símbolo i (por ejemplo, RAM[16]).  

- 5. ¿En qué parte de la memoria se almacena la variable i?  
En RAM[16], que es la primera posición de memoria libre para variables según el ensamblador Hack.

- 6. ¿Qué es entonces una variable?  
Una variable es un nombre simbólico que representa una posición en la memoria RAM usada para guardar un valor. En lenguaje Hack, no hay variables como tal en el hardware, pero el ensamblador las traduce a direcciones de memoria.

- 7. ¿Qué es la dirección de una variable?  
Es la posición de memoria donde se guarda el valor de la variable.

Ejemplo: si i está en RAM[16], entonces su dirección es 16.  

- 8. ¿Qué es el contenido de una variable?  
Es el valor que se encuentra almacenado en la dirección de la variable.

Ejemplo:  
Si i está en RAM[16]
Y RAM[16] = 25
→ Entonces el contenido de la variable i es 25.

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
