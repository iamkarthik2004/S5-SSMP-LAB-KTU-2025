# Experiment No: 9
## Program to Add Two 16-Bit Numbers Using MASM

---

### **Aim**
Write a program to add two 16-bit numbers using MASM.

---

### **Algorithm**
1. Initialize `CL` to `0` and `SI` to `3000H`.
2. Load two bytes from memory at `[SI]` & `[SI+1]` into `AX` (forming the 1st 16-bit number).
3. Load the next two bytes from memory at `[SI+2]` and `[SI+3]` into `BX` (forming the 2nd 16-bit number).
4. Add the 16-bit values in `AX` and `BX`.
5. Store the 16-bit result back into memory starting at the current `[SI+4]`.
6. Check the carry flag:
   - If no carry, store `0` at the next memory location.
   - Else, store `1`.
7. Trigger breakpoint interrupts (`INT 3`) after storing the carry flag indicator.

---

### **Program Code**

```asm
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
```
---
![MASM Addition Output](images/output.png)
