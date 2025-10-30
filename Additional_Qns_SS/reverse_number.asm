CODE SEGMENT
ASSUME CS:CODE
START:
    MOV SI,3000H
    MOV AL,[SI]       ; Load number
    XOR AH,AH
    MOV BL,0          ; BL = reversed number

REVERSE_LOOP:
    MOV AH,0
    MOV DL,10
    DIV DL            ; AL ÷ 10
    MOV CL,AH         ; Remainder
    MOV AH,BL
    MOV BH,10
    MUL BH
    ADD BL,CL
    CMP AL,0
    JNE REVERSE_LOOP

    INC SI
    MOV [SI],BL       ; Store reversed number
    INT 3

CODE ENDS
END START
