#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char label[10], opcode[10], operand[10], code[10], mnemonic[10];
    int locctr = 0, start = 0, length;
    FILE *fp1, *fp2, *fp3, *fp4;

    fp1 = fopen("input.txt", "r");
    fp2 = fopen("optab.txt", "r");
    fp3 = fopen("symtab.txt", "w");
    fp4 = fopen("inter.txt", "w");

    if (!fp1 || !fp2 || !fp3 || !fp4) {
        printf("Error opening files.\n");
        return 1;
    }

    fscanf(fp1, "%s %s %s", label, opcode, operand);
    if (strcmp(opcode, "START") == 0) {
        start = atoi(operand);
        locctr = start;
        fprintf(fp4, "\t%s\t%s\t%s\n", label, opcode, operand);
        fscanf(fp1, "%s %s %s", label, opcode, operand);
    }

    while (strcmp(opcode, "END") != 0) {
        fprintf(fp4, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);

        // ✅ Add label to SYMTAB only if it’s not "**" and not a reserved storage directive
        if (strcmp(label, "**") != 0 && strcmp(opcode, "RESW") != 0 && strcmp(opcode, "RESB") != 0)
            fprintf(fp3, "%s\t%d\n", label, locctr);

        int found = 0;
        rewind(fp2);
        while (fscanf(fp2, "%s %s", code, mnemonic) != EOF)
            if (strcmp(code, opcode) == 0) { found = 1; locctr += 3; break; }

        if (!found) {
            if (!strcmp(opcode, "WORD")) locctr += 3;
            else if (!strcmp(opcode, "RESW")) locctr += 3 * atoi(operand);
            else if (!strcmp(opcode, "RESB")) locctr += atoi(operand);
            else if (!strcmp(opcode, "BYTE")) {
                locctr += (operand[0] == 'C') ? strlen(operand) - 3 : (strlen(operand) - 3) / 2;
            }
        }
        fscanf(fp1, "%s %s %s", label, opcode, operand);
    }

    fprintf(fp4, "%d\t%s\t%s\n", locctr, label, opcode);
    length = locctr - start;
    printf("Program length: %d\n", length);

    fclose(fp1); fclose(fp2); fclose(fp3); fclose(fp4);
    return 0;
}
