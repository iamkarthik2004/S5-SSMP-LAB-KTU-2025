CODE SEGMENT
ASSUME CS:CODE
START:
    MOV SI,3000H
    MOV AL,[SI]     ; Number
    INC SI
    MOV CL,[SI]     ; Count

PRINT_LOOP:
    INT 3           ; Display number (for debugging)
    DEC CL
    JNZ PRINT_LOOP
    INT 3
CODE ENDS
END START
