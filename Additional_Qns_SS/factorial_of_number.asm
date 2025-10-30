CODE SEGMENT
ASSUME CS:CODE
START:
    MOV SI,3000H      ; Memory location where number is stored
    MOV AL,[SI]       ; Load number into AL
    MOV BL,AL         ; Copy number to BL
    DEC BL            ; BL = n - 1
    MOV AH,00H        ; Clear AH before MUL

FACTORIAL:
    MUL BL            ; AX = AL * BL (16-bit result)
    DEC BL            ; Decrement BL
    JNZ FACTORIAL     ; Repeat until BL = 0

    INC SI
    MOV [SI],AL       ; Store lower byte of result
    INC SI
    MOV [SI],AH       ; Store higher byte of result

    INT 3             ; Stop execution
CODE ENDS
END START
