# 🧪 Experiment No: 7  
## PROGRAM TO SORT N NUMBERS USING TRAINER KIT  

### 🎯 AIM  
Write a program to **sort N numbers in ascending order** using the trainer kit.

---

### 🧠 PROGRAM DETAILS  

| **Address** | **Mnemonics** | **Opcode** | **Comment** |
|:------------:|:--------------|:------------|:-------------|
| 2000 | MOV SI, 3000 | C7C6 0030 | Move 3000 to Source Index |
| 2004 | MOV CL, [SI] | 8A00 | Move contents of SI to CL register |
| 2006 | DEC CL | FEC9 | Decrement CL register |
| 2008 | MOV SI, 3000 | C7C6 0030 | Move 3000 to Source Index |
| 200C | MOV CH, [SI] | 8A2C | Move contents of SI to CH register |
| 200E | DEC CH | FECD | Decrement CH register |
| 2010 | INC SI | 46 | Increment Source Index |
| 2011 | MOV AL, [SI] | 8404 | Move contents of SI to AL register |
| 2013 | INC SI | 46 | Increment SI |
| 2014 | CMP AL, [SI] | 3A04 | Compare contents of SI and AL |
| 2016 | JC 201E | 7206 | Jump to location 201E if carry generated |
| 2018 | XCHG AL, [SI] | 8604 | Exchange AL with contents of SI |
| 201A | DEC SI | 4E | Decrement SI |
| 201B | XCHG AL, [SI] | 8604 | Exchange AL with contents of SI |
| 201D | INC SI | 46 | Increment SI |
| 201E | DEC CH | FECD | Decrement CH register |
| 2020 | JNZ 2011 | 75EF | Jump to location 2011 if non-zero result |
| 2022 | DEC CL | FEC9 | Decrement CL register |
| 2024 | JNZ 2008 | 75E2 | Jump to location 2008 if non-zero result |
| 2026 | HLT | F4 | End of Program |

---

### ⚙️ DESCRIPTION  
This program sorts **N numbers** stored in memory in **ascending order** using a **bubble sort algorithm**.  
It repeatedly compares adjacent numbers and swaps them if they are in the wrong order.

---

### 📍 NOTES  
- Data starts from memory location **3000H**.  
- First data byte represents **the number of elements (N)** to be sorted.  
- Remaining bytes represent the numbers to be sorted.  
- The sorted data will overwrite the original data in memory.

---

### ✅ RESULT  
Thus, the program to **sort N numbers in ascending order** using the trainer kit has been successfully executed and verified.
