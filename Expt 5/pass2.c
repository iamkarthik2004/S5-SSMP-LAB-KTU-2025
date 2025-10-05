#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char address[10], label[10], opcode[10], operand[10], length[10], size[10], str_addr[10], a[10];
FILE *fp1, *fp2, *fp3, *fp4, *fp5, *fp6;
int i, j, m, inter_size, text_size;

struct SYMTAB {
    char label[10];
    char address[10];
} ST[30];

struct OPTAB {
    char opcode[10];
    char mnemonic[10];
} OT[30];

struct INTER {
    char address[10];
    char label[10];
    char opcode[10];
    char operand[10];
} IT[30];

void read_OPTAB() {
    int i = 0;
    while (fscanf(fp3, "%s %s", OT[i].opcode, OT[i].mnemonic) == 2) {
        i++;
    }
}

void read_SYMTAB() {
    int i = 0;
    while (fscanf(fp2, "%s %s", ST[i].label, ST[i].address) == 2) {
        i++;
    }
}

void read_INTER() {
    inter_size = 0;
    while (fscanf(fp1, "%s %s %s %s", IT[inter_size].address, IT[inter_size].label, IT[inter_size].opcode, IT[inter_size].operand) == 4) {
        inter_size++;
    }
}

int main() {
    fp1 = fopen("inter.txt", "r");
    fp2 = fopen("symtab.txt", "r");
    fp3 = fopen("optab.txt", "r");
    fp4 = fopen("length.txt", "r");
    fp5 = fopen("assmlist.txt", "w");
    fp6 = fopen("objcode.txt", "w");

    if (!fp1 || !fp2 || !fp3 || !fp4 || !fp5 || !fp6) {
        printf("Error opening one or more files.\n");
        exit(1);
    }

    fscanf(fp4, "%s %s", length, size);
    read_OPTAB();
    read_SYMTAB();
    read_INTER();

    strcpy(address, IT[0].address);
    strcpy(label, IT[0].label);
    strcpy(opcode, IT[0].opcode);
    strcpy(operand, IT[0].operand);

    if (strcmp(opcode, "START") == 0) {
        fprintf(fp5, "%s\t%s\t%s\t%s\t**\n", address, label, opcode, operand);

        unsigned int start_addr = (unsigned int)strtol(operand, NULL, 16);
        unsigned int prog_len = (unsigned int)strtol(length, NULL, 16);
        text_size = (unsigned int)strtol(size, NULL, 16);

        fprintf(fp6, "H^%-6s^%06X^%06X\n", label, start_addr, prog_len);
        fprintf(fp6, "T^%06X^%02X", start_addr, text_size);

        strcpy(str_addr, operand);
    } else {
        strcpy(str_addr, "000000");
    }

    // Process intermediate instructions
    for (i = 1; i < inter_size; i++) {
        strcpy(address, IT[i].address);
        strcpy(label, IT[i].label);
        strcpy(opcode, IT[i].opcode);
        strcpy(operand, IT[i].operand);

        int object_code_size = 0;

        if (strcmp(opcode, "BYTE") == 0) {
            fprintf(fp5, "%s\t%s\t%s\t%s\t", address, label, opcode, operand);
            fprintf(fp6, "^");

            if (operand[0] == 'C') {
                // Calculate the number of bytes needed for the string
                object_code_size = strlen(operand) - 3;
                for (int k = 2; k < strlen(operand) - 1; k++) {
                    fprintf(fp5, "%02X", operand[k]);
                    fprintf(fp6, "%02X", operand[k]);
                }
                fprintf(fp5, "\n");
            } else if (operand[0] == 'X') {
                // Each byte is represented by two hex digits
                object_code_size = (strlen(operand) - 3) / 2;
                for (int k = 2; k < strlen(operand) - 1; k++) {
                    fprintf(fp5, "%c", operand[k]);
                    fprintf(fp6, "%c", operand[k]);
                }
                fprintf(fp5, "\n");
            }

        } else if (strcmp(opcode, "WORD") == 0) {
            sprintf(a, "%06X", atoi(operand));
            fprintf(fp5, "%s\t%s\t%s\t%s\t%s\n", address, label, opcode, operand, a);
            fprintf(fp6, "^%s", a);
            object_code_size = 3;  // WORD is always 3 bytes.

        } else if (strcmp(opcode, "RESB") == 0 || strcmp(opcode, "RESW") == 0) {
            fprintf(fp5, "%s\t%s\t%s\t%s\t**\n", address, label, opcode, operand);
            object_code_size = 0;

        } else if (strcmp(opcode, "END") == 0) {
            fprintf(fp5, "%s\t%s\t%s\t%s\t**\n", address, label, opcode, operand);

        } else {
            m = 0;
            while (m < 30 && strcmp(OT[m].opcode, opcode) != 0) m++;

            j = 0;
            while (j < 30 && strcmp(ST[j].label, operand) != 0) j++;

            // Fix here: resolve the address of the operand (e.g., GAMMA)
            if (j < 30) {  // If the label exists in the symbol table
                // Update the assembly list with the resolved address
                fprintf(fp5, "%s\t%s\t%s\t%s\t%s%s\n", address, label, opcode, operand, OT[m].mnemonic, ST[j].address);
                // Update the object code with the resolved address
                fprintf(fp6, "^%s%s", OT[m].mnemonic, ST[j].address);  // Append the address from the symbol table
            } else {
                // Handle case if the operand is not found in the symbol table (though this shouldn't happen in your case)
                fprintf(fp5, "%s\t%s\t%s\t%s\t**\n", address, label, opcode, operand);
                fprintf(fp6, "****");
            }

            object_code_size = 3; // Standard size for machine instructions (3 bytes).
        }

        // Update the text record size
        if (object_code_size > 0) {
            text_size += object_code_size;
        }
    }

    // Add the END statement to the objcode file
    unsigned int exec_start_addr = (unsigned int)strtol(str_addr, NULL, 16);
    fprintf(fp6, "\nE^%06X\n", exec_start_addr);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
    fclose(fp6);

    return 0;
}

