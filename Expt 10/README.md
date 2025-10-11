# Experiment No: 10
## Program to Multiply Two 16-Bit Numbers Using MASM

---

### **Aim**
Write a program to multiply two 16-bit numbers using MASM.

---

### **Algorithm**
1. Set `SI = 3000H`.
2. Load byte at `[SI]` into `AL`.
3. Increment `SI`; Load byte at `[SI]` into `BL`.
4. Multiply `BL` and `AL`; result stored in `AX`.
5. Increment `SI`; Store `AL` at `[SI]`.
6. Increment `SI`; Store `AH` at `[SI]`.
7. Execute `INT 3` for breakpoint.
8. End program.

---

### **Program Code**

```asm
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
