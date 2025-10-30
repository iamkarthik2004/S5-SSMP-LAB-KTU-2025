#include <stdio.h>

int main() {
    int p, c, i, j, k, count = 0, changed;
    int alc[5][3], max[5][3], need[5][3], available[3], done[5] = {0}, safe[5];

    printf("Enter the number of Process and Resources: ");
    scanf("%d %d", &p, &c);

    printf("Enter allocation of resource of all processes %dx%d matrix:\n", p, c);
    printf("Allocation\n");
    for (i = 0; i < p; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &alc[i][j]);

    printf("Enter the maximum resource process required %dx%d matrix:\n", p, c);
    printf("Max\n");
    for (i = 0; i < p; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &max[i][j]);

    printf("Enter the available resources:\n");
    for (j = 0; j < c; j++)
        scanf("%d", &available[j]);

    printf("\nThe Need matrix is:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < c; j++) {
            need[i][j] = max[i][j] - alc[i][j];
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }

    while (count < p) {
        changed = 0;
        for (i = 0; i < p; i++) {
            if (!done[i]) {
                for (j = 0; j < c && need[i][j] <= available[j]; j++);
                if (j == c) {
                    for (k = 0; k < c; k++)
                        available[k] += alc[i][k];
                        safe[count++] = i + 1;
                        done[i] = 1;
                        changed = 1;
                }
            }
        }
        if (!changed) {
            printf("Safe sequence does not exist.\n");
            return 0;
        }
    }

    printf("\nAvailable resources after completion: ");
    for (j = 0; j < c; j++)
        printf("%d\t", available[j]);
    printf("\nThe system is in a safe state.\n");

    printf("Safe sequence is: <");
    for (i = 0; i < p; i++)
        printf("p%d\t", safe[i]);
    printf(">\n");
    return 0;
}
