CODE SEGMENT
ASSUME CS:CODE
START:
    MOV SI,3000H
    MOV AL,[SI]     ; Number in AL
    MOV BL,AL
    MUL BL          ; AL * BL = A²
    MOV BL,AL
    MOV AL,[SI]
    MUL BL          ; A × A² = A³
    INC SI
    MOV [SI],AL
    INC SI
    MOV [SI],AH
    INT 3
CODE ENDS
END START
