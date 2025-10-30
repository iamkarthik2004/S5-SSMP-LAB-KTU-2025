CODE SEGMENT
ASSUME CS:CODE
START:
    MOV SI,3000H
    MOV AL,[SI]       ; Load number
    XOR AH,AH
    MOV BL,0          ; Sum

SUM_LOOP:
    MOV AH,0
    MOV DL,10
    DIV DL            ; AL ÷ 10
    ADD BL,AH         ; Add remainder
    MOV AH,0
    CMP AL,0
    JNE SUM_LOOP

    INC SI
    MOV [SI],BL       ; Store sum
    INT 3

CODE ENDS
END START
