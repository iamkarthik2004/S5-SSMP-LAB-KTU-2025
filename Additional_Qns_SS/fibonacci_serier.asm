CODE SEGMENT
ASSUME CS:CODE
START:
    MOV SI,3000H      ; Memory location where count (n) is stored
    MOV CL,[SI]       ; CL = number of terms to generate

    MOV AL,00H        ; First term = 0
    MOV BL,01H        ; Second term = 1

    INC SI
    MOV [SI],AL       ; Store first term
    INC SI
    MOV [SI],BL       ; Store second term

    DEC CL            ; We already have 2 terms
    DEC CL

NEXT_TERM:
    MOV AH,AL         ; Copy previous term
    ADD AL,BL         ; AL = AL + BL (next Fibonacci)
    MOV BL,AH         ; Update BL = previous term

    INC SI
    MOV [SI],AL       ; Store next Fibonacci term

    DEC CL
    JNZ NEXT_TERM     ; Repeat until all terms generated

    INT 3
CODE ENDS
END START
