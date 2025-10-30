CODE SEGMENT
ASSUME CS:CODE
START:
    MOV SI,3000H
    MOV AL,[SI]       ; First number
    INC SI
    MOV BL,[SI]       ; Second number

GCD_LOOP:
    CMP BL,0
    JE GCD_DONE
    MOV AH,0
    DIV BL
    MOV AL,BL
    MOV BL,AH
    JMP GCD_LOOP

GCD_DONE:
    MOV CL,AL          ; GCD in CL

    MOV SI,3002H
    MOV [SI],CL        ; Store GCD
    MOV AL,[3000H]
    MOV BL,[3001H]
    MUL BL
    DIV CL
    INC SI
    MOV [SI],AL        ; Store LCM
    INT 3

CODE ENDS
END START
