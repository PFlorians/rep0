 ;;;;;;;;;;;;;;;;;;;
    ;  BIOS MAKRA     ;
    ;;;;;;;;;;;;;;;;;;;
    
    ;;;;;;;;;;;;;;;;;;;
    ;    CONSTANTS    ;
    ;;;;;;;;;;;;;;;;;;;
	X EQU 0
	Y EQU 0
		;;;;;;;;;;;;;;;;;
		; VIDEO MODE SET;
		;;;;;;;;;;;;;;;;;
		SETMODE MACRO
			MOV AX, 0003H
			INT 10H
		ENDM
		;;;;;;;;;;;;;;;;;;
		; CURSPOSITION   ;
		;;;;;;;;;;;;;;;;;;
		;ZISTI POZICIU KURZORA
		READPOS MACRO
			MOV AH, 03H
			MOV BH, 0
			INT 10H
			MOV CURSROW, DH
			MOV CURSCOL, DL
			XOR CX, CX
		ENDM
		;;;;;;;;;;;;;;;;;;;
		;     CLRSCR      ;
		;;;;;;;;;;;;;;;;;;;
		CLEAR MACRO
			MOV AH, 07H
			MOV AL, 0
			MOV BH, 10 ;NULU NECHAT LEN AK ZIADUCE NEPISAT NA PREDOSLE POZICIE
			MOV CH, 0
			MOV CL, 0
			MOV DH, 24	;RIADKY
			MOV DL, 80	;STLPCE
			INT 10H
		ENDM
		;;;;;;;;;;;;;;;;;;
		;   MOVE CURSOR  ;
		;;;;;;;;;;;;;;;;;;
		MOVESTART MACRO ;PRI ROZVINUTI BY NEMALO V DX BYT NIC CO TREBA VYPISAT
			MOV AH, 02H
			MOV BH, 0
			MOV DH, X	
			MOV DL, Y
			INT 10H
		ENDM
