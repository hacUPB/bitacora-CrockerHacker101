
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



# Actividad 3  

- **paso 1** : hacemos el dibujito en el editor.
- **paso 2** : copiamos el código dado por el editor para que se dibuje en el nand2tetris.
- **paso 3** : en el código debemos buscar la linea final donde acaba de dibujar
- **paso 4** : después ponemos un loop que provoque que la pantalla quede en blanco (tiene que tener todos los binaros en 0 para que se quede en blanco).
- **paso 5** : el código hace un loop en: 
  ~~~
  @13  
  A=M   
  D;JMP   
  y ponemos este código:  
  // Borrar la pantalla   
  @SCREEN  
  D=A  
  @0  
  M=D  
  @8192  
  D=A  
  @R1  
  M=D  
  (BORRAR_PANTALLA)  
  @R0  
  A=M  
  M=0  
  @R0  
  M=M+1  
  @R1  
  M=M-1  
  D=M  
  @BORRAR_PANTALLA  
  D;JGT
  ´´´  
- **paso 6**: ponemos @screen para ponernos en la variable de screen, despues declaramos 0 en D, luego guardamos esa dirección en 0 (puntero a donde vamos a escribir). ponemos @8192 ya que ese es el tamaño en pixeles de la pantalla y luego guardamos r1, luego sigue el bucle que borra lo de la pantalla  

# Actividad 4
