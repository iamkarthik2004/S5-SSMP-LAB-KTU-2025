CODE SEGMENT
ASSUME CS:CODE
START:
    MOV SI,3000H
    MOV AL,[SI]     ; A
    INC SI
    MOV BL,[SI]     ; B

    ; A²
    MOV AH,0
    MOV BH,AL
    MUL AL          ; AX = A²
    MOV DX,AX

    ; B²
    MOV AL,BL
    MUL BL
    ADD DX,AX       ; DX = A² + B²

    ; 2AB
    MOV AL,[3000H]
    MOV BL,[3001H]
    MUL BL
    ADD AX,AX       ; AX = 2AB
    ADD DX,AX       ; DX = A² + B² + 2AB

    INC SI
    INC SI
    MOV [SI],DL
    INC SI
    MOV [SI],DH
    INT 3
CODE ENDS
END START
