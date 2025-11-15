# Actividad 1

## ¿Qué es un computador digital moderno?
Un computador digital moderno es una máquina electrónica capaz de recibir, procesar y almacenar datos mediante operaciones lógicas y aritméticas, usando valores binarios (0 y 1). Está diseñado para ejecutar programas que controlan su funcionamiento y le permiten realizar tareas específicas.

## ¿Cuáles son sus partes?
Un computador moderno se compone principalmente de:

- **Unidad Central de Procesamiento (CPU)**: Es el cerebro del computador. Procesa las instrucciones de los programas.
- **Memoria (RAM)**: Almacena temporalmente los datos y programas que están siendo utilizados.
- **Dispositivo de almacenamiento**: Guarda datos de forma permanente.   
- **Ej**: discos duros (HDD), unidades de estado sólido (SSD).
- **Dispositivos de entrada**: Permiten al usuario ingresar información.  
- **Ej**: teclado, mouse, escáner.
- **Dispositivos de salida**: Muestran el resultado del procesamiento.   
- **Ej**: monitor, impresora, altavoces.
- **Placa base (motherboard)**: Conecta y permite la comunicación entre todos los componentes.
- **Fuente de poder**: Provee energía eléctrica a todo el sistema.

---

# Actividad 2 (Bitácora)

## ¿Qué es entonces un programa?
Un programa es un conjunto de instrucciones que le dicen a la computadora qué hacer paso a paso, Estas instrucciones siguen reglas muy específicas para que el hardware pueda entenderlas y ejecutarlas.  

## ¿Qué es un lenguaje ensamblador?
Un lenguaje ensamblador (Assembly) es un lenguaje de bajo nivel que traduce directamente a instrucciones comprensibles por la CPU, pero usando palabras clave simbolicas en lugar de solo números binarios. Es más entendible para los humanos que el lenguaje de máquina, pero sigue estando muy cerca del hardware.

Ejemplo de una instrucción en ensamblador:
~~~
@10
D=A
~~~

## ¿Qué es lenguaje de máquina  

El lenguaje de máquina es el lenguaje real que entiende el procesador, está compuesto solo por ceros y unos (binario).
Cada patrón de bits activa circuitos dentro del CPU, por eso es el nivel más bajo de programación.

Ejemplo:
~~~
0000000000001010   // versión binaria de @10
1110110000010000   // versión binaria de D=A
~~~

# Actividad 3   
## ¿Qué son PC, D y A?  
- **Personal Computer**: Computadora personal. Es un dispositivo electrónico usado por una sola persona a la vez, con capacidad para ejecutar programas, navegar por internet, jugar videojuegos, etc.  
- **A** = Acumulador  
Nombre del registro: AX, EAX o RAX (dependiendo de si es de 16, 32 o 64 bits).
Es el registro principal que se usa para operaciones aritméticas y lógicas. Se llama así porque históricamente era el que “acumulaba” resultados.  
  
- **D** = Data (registro de datos)    
Nombre del registro: DX, EDX o RDX.  
Se usa para operaciones que requieren un segundo registro junto con AX/EAX/RAX.  
Por ejemplo:  
En multiplicaciones y divisiones, DX se usa para almacenar parte del resultado (como el residuo).

# Actividad 4  

Considera el siguiente fragmento de código en lenguaje ensamblador:  
```bash
@16384
D = A
@16
M = D
```
El resultado de este programa es que guarda en la posición 16 de la RAM el valor 16384. Ahora escribe un programa en lenguaje ensamblador que guarde en la posición 32 de la RAM un 100.  

# Actividad 5  

Resumen:

Resumen breve

este explica como funciona el CPU del computador Hack y cómo ejecuta un programa. el CPU trabaja en un ciclo donde toma una instrucción, la interpreta y la ejecuta. Está formado por la ALU, los registros A y D, y el Program Counter, los cuales coordinan los cálculos y el avance del programa.  
También hablo que existen dos tipos de instrucciones:

- A-instructions, que cargan valores o direcciones en el registro A.  
- C-instructions, que realizan operaciones, almacenan resultados o hacen saltos.  

y tambien la instrucción está codificada en bits, y el CPU las decodifica para saber exactamente qué acción debe realizar.  
