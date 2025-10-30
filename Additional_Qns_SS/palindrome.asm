DATA SEGMENT
STRING DB 'AMMA'     ; String to check
LEN    DB 5           ; Length of the string
RESULT DB ?           ; Will store 1 = Palindrome, 0 = Not palindrome
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
    MOV AX,DATA
    MOV DS,AX

    MOV CL,LEN        ; CL = Length of string
    MOV SI,OFFSET STRING
    MOV DI,SI
    ADD DI,CL
    DEC DI            ; DI points to last character

CHECK_LOOP:
    MOV AL,[SI]
    MOV BL,[DI]
    CMP AL,BL
    JNE NOT_PALIN     ; If mismatch → not palindrome

    INC SI
    DEC DI
    CMP SI,DI
    JAE IS_PALIN      ; If crossed → palindrome
    JMP CHECK_LOOP

NOT_PALIN:
    MOV RESULT,0
    JMP END_PROGRAM

IS_PALIN:
    MOV RESULT,1

END_PROGRAM:
    INT 3
CODE ENDS
END START
