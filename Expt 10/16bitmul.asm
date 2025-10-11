CODE SEGMENT
ASSUME CS: CODE
START:
    MOV SI, 3000H      ; Set starting memory address
    MOV AL, [SI]       ; Load first byte
    INC SI
    MOV BL, [SI]       ; Load second byte
    MUL BL             ; Multiply AL by BL; result in AX
    INC SI
    MOV [SI], AL       ; Store lower byte of result
    INC SI
    MOV [SI], AH       ; Store higher byte of result
    INT 3              ; Breakpoint

CODE ENDS
END START
