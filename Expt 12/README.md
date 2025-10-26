# 🧮 Experiment No: 12  
## Interfacing with 8255 (Mode 0)

---

### 🎯 **Aim**
To interface **8255** with the **8086 Trainer Kit** and initiate **Port A as input** and **Port B as output** in **Mode 0**.

---

## 💻 **Program**

| **Address** | **Mnemonics**    | **Comment**                        |
|-------------|------------------|------------------------------------|
| 1000        | MOV AL, 90H      | Load control word 90H into AL      |
| 1003        | OUT C6, AL       | Send control word to control port C6 |
| 1005        | IN AL, C0        | Read data from Port A into AL      |
| 1007        | OUT C2, AL       | Send data from AL to Port B        |
| 1009        | MOV SI, 1100     | Load memory address 1100 into SI   |
| 100B        | MOV [SI], AL     | Store data from AL into memory [SI] |
| 100E        | HLT              | Stop program execution             |

---

### ⚙️ **Explanation**
1. The control word **90H** initializes the **8255 Programmable Peripheral Interface (PPI)** in **Mode 0**, where:  
   - **Port A** → Input  
   - **Port B** → Output  
2. The control word is sent to the control register at port **C6** using the `OUT` instruction.  
3. Data is then **read from Port A (C0)** using `IN AL, C0`.  
4. The same data is **sent to Port B (C2)** using `OUT C2, AL`.  
5. The data received from Port A is also **stored in memory location 1100** for verification.  
6. The program halts after completing the data transfer.

---

### 🧾 **Input / Output**

| **Operation** | **Port / Memory** | **Action** |
|---------------|------------------|-------------|
| Control Word  | C6               | 90H (Mode 0 setup) |
| Input Data    | C0               | Read from Port A |
| Output Data   | C2               | Sent to Port B |
| Memory Store  | 1100             | Save input data for reference |

---

### 🧾 **Result**
The **8255** is successfully interfaced with the **8086 Trainer Kit**.  
Port A operates as **input**, and Port B as **output** in **Mode 0**.  
The data received from Port A is correctly transferred to Port B and stored in memory.

---

### ✅ **Conclusion**
The experiment successfully demonstrates **I/O interfacing using the 8255 PPI in Mode 0**.  
The data flow from Port A to Port B verifies proper configuration and operation.  
**CO3 (Course Outcome 3)** is achieved.

