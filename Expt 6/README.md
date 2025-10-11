# 🧮 Experiment No: 6  
## Addition of Two 16-Bit Numbers

---

### 🎯 **Aim**
Write a program to add two 16-bit numbers by:  
1. Reading the input **within the program**.  
2. Reading the input **from the keyboard using a Trainer Kit**.

---

## 🧠 **Program 1: Input Values Within the Program**

| **Address** | **Mnemonics**   | **Opcode** | **Comment**                              |
|--------------|----------------|-------------|-------------------------------------------|
| 2000         | MOV AX, 0409   | C7C00904    | Store 0409 to AX register                 |
| 2004         | MOV BX, 0501   | C7C30501    | Store 0501 to BX register                 |
| 2008         | ADD AX, BX     | 01D8        | Add elements of AX and BX register        |
| 200A         | MOV [2400], AX | 89060024    | Store result from AX to memory location 2400 |
| 200E         | HLT            | FA          | End of program                            |

---

### ⚙️ **Explanation**
1. The value `0409` is loaded into register **AX**.  
2. The value `0501` is loaded into register **BX**.  
3. The instruction `ADD AX, BX` adds the two 16-bit numbers.  
4. The result (`090A`) is stored at memory location **2400**.  
5. The program halts with the `HLT` instruction.

---

### 🧾 **Output**

| **Address** | **Memory Location** | **Data (Result)** |
|--------------|---------------------|-------------------|
| 0000         | 2400                | 0A                |
| 0000         | 2401                | 09                |

**Result:**  
The sum of `0409` and `0501` is **090A**, which is stored at memory location `2400`.

---

## 💻 **Program 2: Input Values Read from Keyboard**

| **Address** | **Mnemonics** | **Opcode** | **Comment** |
|--------------|----------------|-------------|--------------|
| 2000 | MOV SI, 3000 | C7C60030 | Move memory location 3000 to source index |
| 2004 | MOV AL, [SI] | 8A04 | Move contents of source index to AL register |
| 2006 | INC SI | 46 | Increment Source Index |
| 2007 | MOV AH, [SI] | 8A24 | Move contents of SI to AH register |
| 2009 | INC SI | 46 | Increment SI |
| 200A | MOV BL, [SI] | 8A1C | Move contents of SI to BL register |
| 200C | INC SI | 46 | Increment SI |
| 200D | MOV BH, [SI] | 8A3C | Move contents of SI to BH register |
| 200F | ADD AX, BX | 01D8 | Add contents of AX and BX registers |
| 2011 | INC SI | 46 | Increment SI |
| 2012 | MOV [SI], AL | 8804 | Move contents of AL register to SI location |
| 2014 | INC SI | 46 | Increment SI |
| 2015 | MOV [SI], AH | 8824 | Move contents of AH register to SI location |
| 2017 | HLT | FA | End of program |

---

### 🧩 **Input**

| **Memory Location** | **Data (Hex)** |
|----------------------|----------------|
| 3000 | 09 |
| 3001 | 02 |
| 3002 | 05 |
| 3003 | 05 |

---

### 🧾 **Output**

| **Address** | **Memory Location** | **Data (Result)** |
|--------------|---------------------|-------------------|
| 0000         | 3004                | 0E                |
| 0000         | 3005                | 07                |

**Result:**  
The input values represent:  
- First number = `0209`  
- Second number = `0505`  
Their sum = **070E**, which is stored at memory locations **3004** and **3005**.

---

### ✅ **Conclusion**
Both programs successfully perform the addition of two 16-bit numbers —  
- **Program 1** uses fixed values from the program, while  
- **Program 2** reads values from memory (keyboard input through Trainer Kit).  
In both cases, the result is stored back in memory as a 16-bit sum.
