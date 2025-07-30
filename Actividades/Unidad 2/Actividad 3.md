Actividad 3

- **paso 1** : hacemos el dibujito en el editor.
- **paso 2** : copiamos el código dado por el editor para que se dibuje en el nand2tetris.
- **paso 3** : en el código debemos buscar la linea final donde acaba de dibujar
- **paso 4** : después ponemos un loop que provoque que la pantalla quede en blanco (tiene que tener todos los binaros en 0 para que se quede en blanco).
- **paso 5** : el código hace un loop en: 
  ´´´@13
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
  D;JGT´´´
- **paso 6**: ponemos @screen para ponernos en la variable de screen, despues declaramos 0 en D, luego guardamos esa dirección en 0 (puntero a donde vamos a escribir). ponemos @8192 ya que ese es el tamaño en pixeles de la pantalla y luego guardamos r1, luego sigue el bucle que borra lo de la pantalla
