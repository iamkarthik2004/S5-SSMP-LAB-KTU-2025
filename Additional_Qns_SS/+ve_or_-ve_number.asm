CODE SEGMENT
ASSUME CS:CODE
START:
    MOV SI,3000H       ; Memory location where number is stored
    MOV AL,[SI]        ; Load number into AL

    TEST AL,80H        ; Check sign bit (bit 7)
    JZ POSITIVE        ; If zero → number is positive

NEGATIVE:
    INC SI
    MOV [SI],01H       ; Store 1 → Negative
    INT 3

POSITIVE:
    INC SI
    MOV [SI],00H       ; Store 0 → Positive
    INT 3

CODE ENDS
END START
