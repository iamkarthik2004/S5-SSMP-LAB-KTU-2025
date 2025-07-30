/*
BANKER'S ALGORITHM
*/

#include <stdio.h>

int main() {
    int p, c, count = 0, i, j, terminate = 0;

    printf("Enter the number of Process and Resources: ");
    scanf("%d %d", &p, &c);

    int alc[5][3], max[p][c], need[p][c], safe[p], available[c], done[p];

    printf("Enter allocation of resource of all processes %dx%d matrix:\n", p, c);
    printf("Allocation\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &alc[i][j]);
        }
    }

    printf("Enter the maximum resource process required %dx%d matrix:\n", p, c);
    printf("Max\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the available resources:\n");
    for (i = 0; i < c; i++) {
        scanf("%d", &available[i]);
    }

    printf("\nThe Need matrix is:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < c; j++) {
            need[i][j] = max[i][j] - alc[i][j];
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < p; i++) {
        done[i] = 0;
    }

    while (count < p) {
        for (i = 0; i < p; i++) {
            if (done[i] == 0) {
                for (j = 0; j < c; j++) {
                    if (need[i][j] > available[j]) {
                        break;
                    }
                }
                if (j == c) {
                    safe[count] = i + 1;
                    done[i] = 1;

                    for (j = 0; j < c; j++) {
                        available[j] += alc[i][j];
                    }
                    count++;
                    terminate = 0;
                } else {
                    terminate++;
                }
            }
        }

        if (terminate == p) {
            printf("Safe sequence does not exist.\n");
            break;
        }
    }

    if (terminate != p) {
        printf("\nAvailable resources after completion: ");
        for (i = 0; i < c; i++) {
            printf("%d\t", available[i]);
        }
        printf("\nThe system is in a safe state.\n");

        printf("Safe sequence is: ");
        printf("<");
        for (i = 0; i < count; i++) {
            printf("p%d\t", safe[i]);
        }
        printf(">\n");
    }

    return 0;
}
