
# Actividad 1  

### ¿Qué es la entrada-salida mapeada a memoria?

La entrada-salida mapeada a memoria (Memory-Mapped I/O) es un mecanismo en el que los dispositivos de entrada y salida como la pantalla y el teclado comparten el mismo espacio de direcciones que la memoria RAM del computador, en vez de usar instrucciones especiales de E/S, el programa lee y escribe en direcciones de memoria reservadas para los dispositivos.  

Esas direcciones actúan como una ventana al dispositivo: escribir en ellas cambia el estado del dispositivo (p. ej. pintar píxeles), y leer de ellas devuelve el estado del dispositivo (p. ej. código ASCII de la tecla presionada). En la práctica, esto permite manejar hardware usando las mismas instrucciones de acceso a memoria que ya usa el programa.

### ¿Cómo se implementa en la plataforma Hack?   

La plataforma Hack implementa la entrada-salida mapeada a memoria usando regiones específicas de la RAM que representan directamente la pantalla y el teclado:

Con la Pantalla:  

- Dirección base: 16384 (0x4000)   
- Tamaño: 8192 palabras   
- Cada bit controla un píxel de la pantalla (1 = negro, 0 = blanco).   
- Cada fila de la pantalla se almacena en 32 palabras consecutivas.  
~~~  
@SCREEN    // su valor especifico es @16384
M = 1       // para poner en negro el primer pixel de la pantalla
~~~

Con el teclado:  

- Dirección fija: 24576 (0x6000)  
- Cuando una tecla está presionada, esta ubicación contiene su código ASCII.  
- Si no hay tecla presionada, contiene 0.  
~~~  
@KBD
D = M       // D contiene el código de la tecla presionada
~~~

### Inventa un programa que haga uso de la entrada-salida mapeada a memoria.  

~~~
(LOOP)

// Leer teclado
@KBD
D = M

// Si se presiona una tecla, ir a PINTAR
@PINTAR
D;JGT

// Si no hay tecla, ir a BORRAR
@BORRAR
0;JMP


// -------------------------
// Pintar el primer píxel
// -------------------------
(PINTAR)
@SCREEN
M = 1      // encender píxel
@LOOP
0;JMP


// -------------------------
// Borrar el primer píxel
// -------------------------
(BORRAR)
@SCREEN
M = 0      // apagar píxel
@LOOP
0;JMP

~~~
- Se escribe 1 en RAM 16384  
- Se enciende solo el primer píxel del monitor (esquina superior izquierda)  

### ¿Cómo investigar el funcionamiento del programa usando el simulador?

Para analizar cómo funciona un programa en la plataforma Hack, se utiliza el CPU Emulator incluido en las herramientas de Nand2Tetris. Este simulador permite ejecutar paso a paso el código y observar cómo afecta la memoria, los registros y los dispositivos de entrada/salida, para esto hacemos lo siguiente:  

- 1. Abrir el CPU Emulator: Ejecuta la herramienta llamada CPU Emulator desde la carpeta tools.  

- 2. Cargar el programa: Puedes cargar:  
- un archivo .asm (el simulador lo ensambla automáticamente)  
- un archivo .hack ya ensamblado.  

- 3. Configurar la visualización

Activa lo que necesites:

**No Animation** (para que corra más rápido)

**Animation** (si quieres ver cada instrucción)

Paneles como:  
- Registers  
- RAM  
- Screen  
- Keyboard  

- 4. Ejecutar el programa:Se puede usar:

- Run (ejecutar continuo)  
- Step (una instrucción a la vez)  
- Step Over (salta llamadas pequeñas)  
- Reset (reiniciar ejecución)  

- 5. Observar el comportamiento: Dependiendo del programa, debes observar:

- Pantalla (Screen): Verás cómo cambia la pantalla según los valores escritos en la memoria desde RAM[16384] hacia arriba.  
- Teclado (Keyboard): Puedes simular teclas escribiendo su código ASCII en el panel Keyboard del simulador.  
- Memoria (RAM): Revisa qué direcciones cambia el programa y cómo.  
- Registros (D, A, PC): Observa cómo cambian después de cada instrucción.  

# Actividad 2

si lo entendi.

# Actividad 3  
Codigo del punto 20 img 18


<img width="1785" height="1063" alt="Captura de pantalla 2025-11-15 151246" src="https://github.com/user-attachments/assets/5d3fda41-1a7e-4780-940c-94950f5aa2f7" />


~~~
// ASCII de 'd' = 100 decimal

(LOOP)
    // Leer teclado
    @KBD
    D=M
    @100      // ASCII 'd'
    D=D-A
    @DRAW
    D;JEQ     // si D == 0 → tecla 'd' presionada

// Si NO se presiona 'd': borrar
(CLEAR)
    @SCREEN
    D=A
    @addr
    M=D        // addr = SCREEN

    @8
    D=A
    @rows
    M=D        // 8 filas a borrar

(CLEAR_LOOP)
    @addr
    A=M
    M=0        // borrar fila

    @addr
    D=M
    @32
    D=D+A      // siguiente fila gráfica
    @addr
    M=D

    @rows
    MD=M-1
    @CLEAR_LOOP
    D;JGT

    @LOOP
    0;JMP


// Cuando se presiona 'd', dibujar imagen 8x8
(DRAW)
    @SCREEN
    D=A
    @addr
    M=D        // addr = SCREEN

    @8
    D=A
    @rows
    M=D        // 8 filas

(DRAW_LOOP)
    @255       // 11111111 en binario → 8 píxeles negros
    D=A
    @addr
    A=M
    M=D        // pinta fila

    @addr
    D=M
    @32
    D=D+A
    @addr
    M=D        // siguiente fila

    @rows
    MD=M-1
    @DRAW_LOOP
    D;JGT

    @LOOP
    0;JMP
~~~

# Actividad 4

Variacion del programa: 

d = 100
e = 101

~~~ 
// d → dibuja
// e → borra

(LOOP)
    // Leer teclado
    @KBD
    D=M            // D = código ASCII o 0

    // ¿Se presionó 'd'? (100)
    @100
    D=D-A
    @DRAW
    D;JEQ          // Si D == 0 → presionaron 'd'

    // Volver a leer teclado porque modificamos D
    @KBD
    D=M

    // ¿Se presionó 'e'? (101)
    @101
    D=D-A
    @CLEAR
    D;JEQ          // Si D == 0 → presionaron 'e'

    // Si ninguna de las dos teclas: seguir en loop
    @LOOP
    0;JMP


// -----------------------------------------
// DIBUJAR IMAGEN 8x8  (de reto 18)
// -----------------------------------------
(DRAW)
    @SCREEN
    D=A
    @addr
    M=D           // addr = SCREEN

    @8
    D=A
    @rows
    M=D           // 8 filas a dibujar

(DRAW_LOOP)
    @255          // 8 pixeles negros: 11111111
    D=A
    @addr
    A=M
    M=D           // dibujar fila

    @addr
    D=M
    @32
    D=D+A         // avanzar 32 palabras = una fila visual
    @addr
    M=D

    @rows
    MD=M-1        // rows--
    @DRAW_LOOP
    D;JGT

    @LOOP
    0;JMP


// -----------------------------------------
// BORRAR IMAGEN 8x8
// -----------------------------------------
(CLEAR)
    @SCREEN
    D=A
    @addr
    M=D          // addr = SCREEN

    @8
    D=A
    @rows
    M=D          // 8 filas a borrar

(CLEAR_LOOP)
    @addr
    A=M
    M=0          // borrar fila

    @addr
    D=M
    @32
    D=D+A
    @addr
    M=D          // siguiente fila gráfica

    @rows
    MD=M-1
    @CLEAR_LOOP
    D;JGT

    @LOOP
    0;JMP
~~~
