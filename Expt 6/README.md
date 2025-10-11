# 🧮 Experiment No: 6  
## Addition of Two 16-Bit Numbers

### 🎯 **Aim**
Write a program to add two 16-bit numbers by reading the input in the program and reading the input from the keyboard using a Trainer Kit.

---

## 🧠 **Program 1: Input Values Within the Program**

| **Address** | **Mnemonics**     | **Opcode** | **Comment**                              |
|--------------|------------------|-------------|-------------------------------------------|
| 2000         | MOV AX, 0409     | C7C00904    | Store 0409 to AX register                 |
| 2004         | MOV BX, 0501     | C7C30501    | Store 0501 to BX register                 |
| 2008         | ADD AX, BX       | 01D8        | Add elements of AX and BX register        |
| 200A         | MOV [2400], AX   | 89060024    | Store result from AX to memory location 2400 |
| 200E         | HLT              | FA          | End of program                            |

---

### ⚙️ **Explanation**
1. The value `0409` is loaded into register **AX**.  
2. The value `0501` is loaded into register **BX**.  
3. The instruction `ADD AX, BX` adds the two 16-bit numbers.  
4. The result is stored at memory location **2400**.  
5. The program halts with the `HLT` instruction.

---

### 🧾 **Result**
The program successfully adds two 16-bit numbers and stores the result in memory location `2400`.
