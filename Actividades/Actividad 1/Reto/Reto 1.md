
//1 punto  
@1978  
D=A  
//hola  

//2 punto  
@69  
D=A  
@100  
M=D  
//  

//3 punto  
@24  
D=M  
@200  
M=D  
//  

//4 punto  
@100  
D=M  
@15  
D=D-A  
@100  
M=D  
//  

//5 punto  
@0  
D=M  
@1  
D=D+M  
@69  
D=D+A  
@2  
M=D  
//  

//6 punto  
D;JEQ  
//  

//7 punto  
@100  
D=M  
@100  
D=D-A  
@20  
D;JLT  
//

//punto 8
//- **¿Que hace el Programa?**    
este programa permite darle valores a las 3 variables y sumarlas en la RAM en R16 ya que R0-R15 ya estan ocupadas.    
  
- **En qué posición de la memoria está var1, var2 y var3? ¿Por qué en esas posiciones?**    
como lo dije previamente se guarda en las posiciones R16 para arriba, ya que, de R0 a R15 ya estan ocupadas por registros generales.
 //

//punto 9
 //
- **¿Qué hace este programa?**   
asigna valores en "i" como 1 y en "sum" como 2 despues los suma.  
- **¿En qué parte de la memoria RAM está la variable i y sum? ¿Por qué en esas posiciones?**  
al ser variable se guardan desde R16 etc; por lo tanto i esta en 16 y sum en 17  
- **Optimiza esta parte del código para que use solo dos instrucciones:**  
@i
M=M+1
 
//punto 10

@R0
D=M
D=D+D
@R1
M=D

//punto 11 
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

//punto 12   
@R1  
D=M  
@R2  
D=D+M  
@69  
D=D+A  
@R4  
M=D  
//  

//punto 13  
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
//  

//punto 14  


