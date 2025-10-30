DATA SEGMENT
MSG1 DB 'Enter a 3-digit number: $'
MSG2 DB 0AH,0DH,'Armstrong number$'
MSG3 DB 0AH,0DH,'Not an Armstrong number$'
NUMSTR DB 5, ?, 5 DUP(?)   ; Input buffer for number (string)
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
    MOV AX,DATA
    MOV DS,AX

    ; ---- PRINT MESSAGE ----
    LEA DX,MSG1
    MOV AH,09H
    INT 21H

    ; ---- INPUT NUMBER ----
    MOV AH,0AH
    LEA DX,NUMSTR
    INT 21H

    MOV CL,[NUMSTR+1]       ; Get input length
    LEA SI,NUMSTR+2         ; Pointer to entered digits

    ; ---- CONVERT ASCII → NUMBER ----
    XOR BX,BX
NEXT_DIGIT:
    MOV AL,[SI]
    SUB AL,'0'
    MOV AH,0
    MOV DX,10
    MUL DX
    ADD BX,AX
    INC SI
    DEC CL
    JNZ NEXT_DIGIT
    MOV DX,BX               ; DX = original number
    MOV CX,3                ; 3 digits

    ; ---- FIND SUM OF CUBES ----
    XOR AX,AX
    XOR BX,BX               ; BX = sum
SUM_LOOP:
    MOV AX,DX
    XOR DX,DX
    MOV CX,10
    DIV CX                  ; divide by 10
    MOV CL,DL               ; remainder = one digit

    MOV AL,CL
    MOV BL,AL
    MUL BL                  ; AX = digit²
    MUL BL                  ; AX = digit³
    ADD BX,AX               ; BX += cube
    MOV DX,AX               ; restore quotient
    MOV AX,DX
    MOV DX,AX
    CMP DX,0
    JNE SUM_LOOP

    ; ---- COMPARE RESULT ----
    CMP BX,DX               ; BX = sum of cubes, DX = original
    JE IS_ARM
NOT_ARM:
    LEA DX,MSG3
    MOV AH,09H
    INT 21H
    JMP EXIT

IS_ARM:
    LEA DX,MSG2
    MOV AH,09H
    INT 21H

EXIT:
    MOV AH,4CH
    INT 21H
CODE ENDS
END START
