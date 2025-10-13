# Pass 2 Assembler – SSMP Lab (KTU 2025)

This project contains the **Pass 2** implementation of a two-pass assembler written in **C** as part of the **S5 SSMP Lab (KTU 2025)**.  
The program reads the **intermediate**, **opcode**, **symbol**, and **length** files generated from **Pass 1**, and produces the final **Object Program** and **Assembly Listing**.

---

## 📂 Files in this project

| File Name | Type | Description |
|------------|------|-------------|
| [pass2.c](https://github.com/iamkarthik2004/S5-SSMP-LAB-KTU-2025/blob/main/Expt%205/pass2.c) | Source code | C program implementing Pass 2 of the assembler |
| [length.txt](https://github.com/iamkarthik2004/S5-SSMP-LAB-KTU-2025/blob/main/Expt%205/length.txt) | Input file | Contains the program name, starting address, and program length |
| [optab.txt](https://github.com/iamkarthik2004/S5-SSMP-LAB-KTU-2025/blob/main/Expt%205/optab.txt) | Input file | Opcode table with mnemonics and corresponding machine codes |
| [symtab.txt](https://github.com/iamkarthik2004/S5-SSMP-LAB-KTU-2025/blob/main/Expt%205/symtab.txt) | Input file | Symbol table generated from Pass 1 containing symbols and addresses |
| [inter.txt](https://github.com/iamkarthik2004/S5-SSMP-LAB-KTU-2025/blob/main/Expt%205/inter.txt) | Input file | Intermediate file generated from Pass 1 containing line-by-line assembly data |
| [assmlist.txt](https://github.com/iamkarthik2004/S5-SSMP-LAB-KTU-2025/blob/main/Expt%205/assmlist.txt) | Output file | Assembly listing file showing addresses, labels, opcodes, operands, and object codes |
| [objcode.txt](https://github.com/iamkarthik2004/S5-SSMP-LAB-KTU-2025/blob/main/Expt%205/objcode.txt) | Output file | Final object program file generated in SIC object format |

---

## ⚙️ Program Flow

1. Read program details (name, start address, length) from `length.txt`.  
2. Load the **Opcode Table (OPTAB)** and **Symbol Table (SYMTAB)** into memory.  
3. Process each line of `inter.txt` to:
   - Match mnemonics with their machine opcodes.
   - Resolve symbol addresses from `symtab.txt`.
   - Generate the corresponding object code.
4. Write formatted output into:
   - `assmlist.txt` → Detailed assembly listing.
   - `objcode.txt` → SIC-formatted object program.

---

## 🧾 Example Output

### `assmlist.txt`
