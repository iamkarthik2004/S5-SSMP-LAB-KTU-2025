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
# 🧩 Steps to Execute 8086 Assembly Program (MASM)

This guide explains how to assemble, link, and execute an **8086 Assembly Language Program** using **MASM** and **DEBUG**.

---

## 1️⃣ Mount the 8086 Drive

If MASM/8086 Simulator is installed in **C drive**:
```bash
mount c c:/8086 
```
If installed in D drive:
```
mount c d:/8086
```
## 2️⃣ Open and Edit the Program
Create or modify your assembly file:
 ```
edit filename.asm
```
✏️ Type your full assembly program, then Save → Exit the editor.

## 3️⃣ Assemble the Program
Assemble your .asm file using MASM:
```
masm filename.asm
```
➡️ Press Enter three times when prompted for:

Object file name

Listing file name

Cross-reference file name 

## 4️⃣ Link the Object File
Link the .obj file to generate an executable:
```
link filename.obj
```

➡️ Again, press Enter three times when prompted.

## 5️⃣ Run the Program in DEBUG Mode

Start the debugger:
```
debug filename.exe
```

## 6️⃣ Trace or Execute Instructions

To trace line-by-line:
```
-t
```

To execute the program completely (until INT 3):

```
-g = 0000
```

## 7️⃣ Enter Input Values in Memory

Set input data starting from memory address 3000H:
```
-e 3000
```

Then enter the data bytes manually.
Example:
```
075A:3000 B8.09 06.02 00.05 50.05
```
## 8️⃣ Execute the Program

Run the program after entering inputs:
```
-g = 0000
```

## 9️⃣ Display Memory Contents

Check the result stored in memory (from 3000H to 3005H):
```
-d 3000,3005
```

🧾 Example Output:
```
075A:3000 09 02 05 0E 07
```
| Step | Command              | Description          |
| ---- | -------------------- | -------------------- |
| 1    | `mount c c:/8086`    | Mount MASM drive     |
| 2    | `edit filename.asm`  | Create/Edit program  |
| 3    | `masm filename.asm`  | Assemble source      |
| 4    | `link filename.obj`  | Link object file     |
| 5    | `debug filename.exe` | Start debugger       |
| 6    | `-t` or `-g=0000`    | Trace or run program |
| 7    | `-e 3000`            | Enter input data     |
| 8    | `-g=0000`            | Execute program      |
| 9    | `-d 3000,3005`       | Display results      |

---
### Output
![MASM Addition Output](https://github.com/iamkarthik2004/S5-SSMP-LAB-KTU-2025/blob/main/Expt%209/16addoutput.png)
