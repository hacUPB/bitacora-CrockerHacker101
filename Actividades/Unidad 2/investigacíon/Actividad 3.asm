
(LOOP)
    // Leer teclado
    @KBD
    D=M
    @100
    D=D-A
    @DRAW
    D;JEQ     // Si se presiona 'd' → dibujar

// No se presiona 'd' → borrar
(CLEAR)
    @SCREEN
    D=A
    @addr
    M=D       // addr = SCREEN

    @4
    D=A
    @rows
    M=D       // 4 filas

(CLEAR_LOOP)
    @addr
    A=M
    M=0       // borrar fila

    @addr
    D=M
    @32
    D=D+A
    @addr
    M=D       // siguiente fila

    @rows
    MD=M-1
    @CLEAR_LOOP
    D;JGT

    @LOOP
    0;JMP


// Dibujar imagen 4x4
(DRAW)
    @SCREEN
    D=A
    @addr
    M=D       // addr = SCREEN

    @4
    D=A
    @rows
    M=D       // 4 filas

(DRAW_LOOP)
    @15        // 1111 → 4 pixeles negros
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
    @DRAW_LOOP
    D;JGT

    @LOOP
    0;JMP
