// 1 punto  
~~~
@1978  
D=A  
~~~
<img width="2996" height="1453" alt="image" src="https://github.com/user-attachments/assets/4daf80af-691b-4235-b29a-b8c178611528" />

// 2 punto  
~~~
@69  
D=A  
@100  
M=D  
~~~
 
<img width="2986" height="1454" alt="image" src="https://github.com/user-attachments/assets/169b31e4-178d-410c-9192-c4d4444ffa23" />

// 3 punto  
~~~
@24  
D=M  
@200  
M=D  
~~~
<img width="2988" height="1365" alt="image" src="https://github.com/user-attachments/assets/dac841bd-c768-4bbc-b7f6-50f6a73e38ad" />

// 4 punto  
~~~
@100  
D=M  
@15  
D=D-A  
@100  
M=D  
~~~
<img width="2996" height="1456" alt="image" src="https://github.com/user-attachments/assets/a04909b3-988b-4853-a719-0004e46a61ac" />


// 5 punto  
~~~
@0  
D=M  
@1  
D=D+M  
@69  
D=D+A  
@2  
M=D  
~~~
<img width="2996" height="1445" alt="image" src="https://github.com/user-attachments/assets/ea798129-784b-4f4b-b48b-8d5b46921d6c" />


// 6 punto  
D;JEQ  
//  

// 7 punto  
~~~
@100  
D=M  
@100  
D=D-A  
@20  
D;JLT  
~~~
<img width="2988" height="1444" alt="image" src="https://github.com/user-attachments/assets/685e068c-56a8-46b2-8baf-cddde935acfc" />



// punto 8
//- **¿Que hace el Programa?**    
este programa permite darle valores a las 3 variables y sumarlas en la RAM en R16 ya que R0-R15 ya estan ocupadas.    
  
- **En qué posición de la memoria está var1, var2 y var3? ¿Por qué en esas posiciones?**    
como lo dije previamente se guarda en las posiciones R16 para arriba, ya que, de R0 a R15 ya estan ocupadas por registros generales.
 //

// punto 9
 //
- **¿Qué hace este programa?**   
asigna valores en "i" como 1 y en "sum" como 2 despues los suma.  
- **¿En qué parte de la memoria RAM está la variable i y sum? ¿Por qué en esas posiciones?**  
al ser variable se guardan desde R16 etc; por lo tanto i esta en 16 y sum en 17  
- **Optimiza esta parte del código para que use solo dos instrucciones:**  
@i
M=M+1
 
// punto 10
~~~
@R0
D=M
D=D+D
@R1
M=D
~~~
// punto 11 
- **¿Qué hace este programa?**  
este programa muestra un loop que le resta 1 a 1000 es vendria siendo "i" hasta que sea 0.  
por lo tanto el proceso llega hasta una linea que provoca que se reinicie hasta que "i" sea 0 y el programa pueda continuar    
- **En qué memoria está almacenada la variable i? ¿En qué dirección de esa memoria?**
al ser una variable este se guarda en R16 en la RAM
- **¿En qué memoria y en qué dirección de memoria está almacenado el comentario //i = 1000?**
al ser una anotacion este no se guarda en ninguna parte de la memoria ya que son de uso humano para indicar que hace cada cosa  
- **¿Cuál es la primera instrucción del programa anterior? ¿En qué memoria y en qué dirección de memoria está almacenada esa instrucción?**  
la primera instruccion es @1000 que se guarda en A en la ROM em 0
- **¿Qué son CONT y LOOP?**  
son etiquetas que marcan posiciones en el código, para permitir saltos con instrucciones  
- **¿Cuál es la diferencia entre los símbolos i y CONT?**  
"i" es una variable y "CONT" una etiqueta  

// punto 12   
~~~
@R1  
D=M  
@R2  
D=D+M  
@69  
D=D+A  
@R4  
M=D  
~~~
<img width="2998" height="1465" alt="image" src="https://github.com/user-attachments/assets/6381ef68-2ea0-40b7-80ab-4ae5d3b18756" />
  

// punto 13  
~~~
@R0  
D=M  
@POS  
D;JGE  
@R1  
M=-1  
@CONT  
0;JMP  
(POS)  
@R1  
M=1  
(CONT)  
~~~
<img width="2998" height="1521" alt="image" src="https://github.com/user-attachments/assets/23ee641b-421b-480f-adb8-0ea4558924a6" />


// punto 14  
~~~
@R1
A=M
D=M
@R4
M=D
~~~
  <img width="2997" height="1442" alt="image" src="https://github.com/user-attachments/assets/af42d62c-825d-4977-9956-21d470bf9514" />

// punto 15  
~~~
@R0  
D=M  
@START  
M=D  
@R1  
D=M  
@END  
M=D  
@COUNT  
M=0  
(LOOP)  
@COUNT  
D=M  
@END  
D=D-M  
@STOP  
D;JEQ  
@START  
A=M  
M=-1  
@START  
D=M  
@1  
D=D+1  
@START  
M=D  
@COUNT  
D=M  
@1  
D=D+1  
@COUNT  
M=D  
@LOOP  
0;JMP  
(STOP)  
@STOP  
0;JMP  
~~~
  <img width="3004" height="1457" alt="image" src="https://github.com/user-attachments/assets/863f8695-70b5-4d56-a2b9-a12428ac2071" />


// punto 16  
~~~
@0  
M=0  
@0  
D=A  
@R1  
M=D  
(LOOP)  
@R1  
D=M  
@10  
D=D-A  
@END  
D;JGE  
@R1  
D=M  
@200  
A=D+A  
D=M  
@0  
M=D+M  
@R1  
M=M+1  
@LOOP  
0;JMP  
(END)  
@END  
0;JMP  
~~~

<img width="2999" height="1460" alt="image" src="https://github.com/user-attachments/assets/3e78ea54-be85-40c8-aafc-936b87f32c4e" />
<img width="2300" height="1477" alt="Captura de pantalla 2025-11-15 180238" src="https://github.com/user-attachments/assets/825e77a2-15f9-4842-bd24-751fdaeaa7b1" />
<img width="2998" height="1466" alt="Captura de pantalla 2025-11-15 180232" src="https://github.com/user-attachments/assets/6b9cd739-d990-4d00-a616-eb2ff0b758c1" />


// punto 17  
~~~
@7  
D=D-A  
@69  
D;JEQ  
~~~
 <img width="3001" height="1476" alt="image" src="https://github.com/user-attachments/assets/11c4842c-dee6-431b-a0d4-c7c063cd4a06" />

// punto 19  
- **Que hace este Programa?**  
mientras mantienes presionada una tecla, se va llenando la memoria de la pantalla con -1 (píxeles encendidos) desde el inicio hacia el final; al soltarla, recorre en sentido inverso apagando esos pixeles, creando un efecto de “llenado/vaciado” de la pantalla controlado por el teclado.
    
// punto 18
<img width="1593" height="951" alt="image" src="https://github.com/user-attachments/assets/135f03b6-79d8-4fbe-a1f7-ab878c4c2ee3" />  
  
// punto 20  
~~~
(LOOP)  
@KBD  
D=M  
@100  
D=D-A  
@DRAW  
D;JEQ  
@LOOP  
0;JMP  
(DRAW)  
@SCREEN  
D=A  
@addr  
M=D  
@4  
D=A  
@rows  
M=D  
(ROW_LOOP)  
@15  
D=A  
@addr  
A=M  
M=D  
@addr  
D=M  
@32  
D=D+A  
@addr  
M=D  
@rows  
MD=M-1  
@ROW_LOOP  
D;JGT  
@LOOP  
0;JMP  
~~~

<img width="2993" height="1460" alt="Captura de pantalla 2025-11-15 180422" src="https://github.com/user-attachments/assets/9b03280a-7db0-47f7-9014-c466fb1052a6" />

<img width="2998" height="1506" alt="image" src="https://github.com/user-attachments/assets/bd6bfe1d-e70a-4b8f-83d3-6fe4b6ab4103" />

para hacer que el programa pase de numero tenemos que presionar la tecla "D".
