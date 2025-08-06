#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char label[20], opcode[20], operand[20];
    char code[20], mnemonic[20];
    char line[100];
    int locctr, start = 0, length;

    FILE *input = fopen("input.txt", "r");
    FILE *optab = fopen("optab.txt", "r");
    FILE *symtab = fopen("symtab.txt", "w");
    FILE *output = fopen("output.txt", "w");

    if (!input || !optab || !symtab || !output) {
        printf("Error opening files.\n");
        return 1;
    }

    // Read first line
    fgets(line, sizeof(line), input);
    int count = sscanf(line, "%s %s %s", label, opcode, operand);

    if (strcmp(opcode, "START") == 0) {
        start = (int)strtol(operand, NULL, 16);
        locctr = start;
        fprintf(output, "%04X\t%s\t%s\t%s\n", locctr, label, opcode, operand);
    } else {
        locctr = 0;
        strcpy(operand, opcode);
        strcpy(opcode, label);
        strcpy(label, "-");
    }

    // Process remaining lines
    while (fgets(line, sizeof(line), input)) {
        count = sscanf(line, "%s %s %s", label, opcode, operand);

        if (count == 2) {
            strcpy(operand, opcode);
            strcpy(opcode, label);
            strcpy(label, "-");
        }

        fprintf(output, "%04X\t%s\t%s\t%s\n", locctr, label, opcode, operand);

        if (strcmp(opcode, "END") == 0)
            break;

        if (strcmp(label, "-") != 0) {
            fprintf(symtab, "%s\t%04X\n", label, locctr);
        }

        // Check opcode in OPTAB
        int found = 0;
        rewind(optab);
        while (fscanf(optab, "%s %s", code, mnemonic) != EOF) {
            if (strcmp(opcode, code) == 0) {
                locctr += 3;
                found = 1;
                break;
            }
        }

        if (!found) {
            if (strcmp(opcode, "WORD") == 0)
                locctr += 3;
            else if (strcmp(opcode, "RESW") == 0)
                locctr += 3 * atoi(operand);
            else if (strcmp(opcode, "RESB") == 0)
                locctr += atoi(operand);
            else if (strcmp(opcode, "BYTE") == 0) {
                if (operand[0] == 'C')
                    locctr += strlen(operand) - 3;
                else if (operand[0] == 'X')
                    locctr += (strlen(operand) - 3) / 2;
            } else {
                printf("Invalid opcode: %s\n", opcode);
            }
        }
    }

    length = locctr - start;
    printf("Program length = %X\n", length);

    fclose(input);
    fclose(optab);
    fclose(symtab);
    fclose(output);

    return 0;
}
