CODE SEGMENT
ASSUME CS:CODE
START:
    MOV SI,3000H
    MOV AL,[SI]        ; Load number
    MOV BL,2
    MOV BH,0
    MOV CL,0           ; Flag for composite

CHECK:
    MOV AH,0
    MOV DL,BL
    DIV DL             ; AL ÷ BL → remainder in AH
    CMP AH,0
    JE NOT_PRIME
    INC BL
    CMP BL,AL
    JL CHECK

PRIME:
    INC SI
    MOV [SI],01H       ; 1 = Prime
    INT 3

NOT_PRIME:
    INC SI
    MOV [SI],00H       ; 0 = Not Prime
    INT 3

CODE ENDS
END START
