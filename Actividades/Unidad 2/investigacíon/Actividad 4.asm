// Programa Hack Assembly: Mostrar imagen con 'd' y borrar con 'e'

(LOOP)
    @KBD
    D=M

    @100
    D=D-A
    @DRAW
    D;JEQ

    @KBD
    D=M

    @101
    D=D-A
    @CLEAR
    D;JEQ

    @LOOP
    0;JMP

(DRAW)
    @SCREEN
    D=A
    @addr
    M=D

    @8
    D=A
    @rows
    M=D

(DRAW_LOOP)
    @255
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

(CLEAR)
    @SCREEN
    D=A
    @addr
    M=D

    @8
    D=A
    @rows
    M=D

(CLEAR_LOOP)
    @addr
    A=M
    M=0

    @addr
    D=M
    @32
    D=D+A
    @addr
    M=D

    @rows
    MD=M-1
    @CLEAR_LOOP
    D;JGT

    @LOOP
    0;JMP
