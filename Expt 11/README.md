# EXPERIMENT 11: INTERFACING WITH STEPPER MOTOR

## AIM
Interfacing a stepper motor using the 8086 Trainer Kit.

## PROGRAM

| ADDRESS | MNEMONICS      | COMMENT             |
|---------|----------------|-------------------|
| 1000    | MOV DI, 2000   | DI ← 2000          |
| 1004    | MOV CL, 04     | CL ← 04            |
| 1007    | MOV AL, [DI]   | AL ← [DI]          |
| 1009    | OUT CL, [DI]   | CO ← AL            |
| 100B    | MOV BX, 1010   | BX ← 1010          |
| 100F    | DEC BX         | Decrement BX       |
| 1010    | JNZ 100F       | Jump to 100F if Z ≠ 0 |
| 1013    | INC DI         | Increment DI       |
| 1015    | LOOP 1007      | Decrement CX and jump to 1007 |
| 1018    | HLT            | Stop execution     |

## RESULT
The stepper motor is successfully interfaced with the 8086 Trainer Kit. The output is verified and the experiment satisfies CO3.
