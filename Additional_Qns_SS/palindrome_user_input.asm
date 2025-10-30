DATA SEGMENT
MSG1 DB 'Enter a word: $'
MSG2 DB 0AH,0DH,'Palindrome$'
MSG3 DB 0AH,0DH,'Not Palindrome$'
STRING DB 20 DUP(?)       ; buffer for input (max 20 chars)
LEN DB ?                  ; length of input
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
    MOV AX,DATA
    MOV DS,AX

    ; --- DISPLAY INPUT MESSAGE ---
    LEA DX,MSG1
    MOV AH,09H
    INT 21H

    ; --- READ STRING FROM USER ---
    MOV AH,0AH
    LEA DX,STRING
    INT 21H

    ; First byte of STRING = max length
    ; Second byte = actual length entered
    MOV AL,[STRING+1]
    MOV LEN,AL

    ; --- SET POINTERS ---
    LEA SI,STRING+2        ; start of string
    MOV CL,LEN
    MOV CH,0
    MOV DI,SI
    ADD DI,CX
    DEC DI                 ; point to last character

CHECK_LOOP:
    MOV AL,[SI]
    MOV BL,[DI]
    CMP AL,BL
    JNE NOT_PALIN
    INC SI
    DEC DI
    CMP SI,DI
    JB CHECK_LOOP
    ; If we reach here, it's palindrome
IS_PALIN:
    LEA DX,MSG2
    MOV AH,09H
    INT 21H
    JMP END_PROGRAM

NOT_PALIN:
    LEA DX,MSG3
    MOV AH,09H
    INT 21H

END_PROGRAM:
    MOV AH,4CH
    INT 21H
CODE ENDS
END START
