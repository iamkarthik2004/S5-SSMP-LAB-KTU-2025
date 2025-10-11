CODE SEGMENT
ASSUME CS:CODE
START:
    MOV CL, 00H        ; Initialize carry indicator
    MOV SI, 3000H      ; Set starting memory address

    ; Load first 16-bit number into AX
    MOV AL, [SI]
    INC SI
    MOV AH, [SI]
    INC SI

    ; Load second 16-bit number into BX
    MOV BL, [SI]
    INC SI
    MOV BH, [SI]

    ; Add the two 16-bit numbers
    ADD AX, BX

    ; Store result at [SI+4]
    INC SI
    MOV [SI], AL
    INC SI
    MOV [SI], AH

    ; Check for carry
    JC L1
    INC SI
    MOV [SI], CL      ; No carry, store 0
    INT 3             ; Breakpoint
L1:
    INC CL
    INC SI
    MOV [SI], CL      ; Carry occurred, store 1
    INT 3             ; Breakpoint

CODE ENDS
END START
