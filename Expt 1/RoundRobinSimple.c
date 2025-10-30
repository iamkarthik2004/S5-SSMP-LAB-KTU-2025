#include <stdio.h>

int main() {
    int n, quantum;
    printf("Enter no. of processes: ");
    scanf("%d", &n);

    int BT[n], rem[n], wt[n], tat[n], i, t = 0;
    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &BT[i]);
        rem[i] = BT[i];
        wt[i] = 0;
    }
    printf("Enter quantum: ");
    scanf("%d", &quantum);

    printf("\nGantt Chart\n0");
    int done;
    do {
        done = 1;
        for (i = 0; i < n; i++) {
            if (rem[i] > 0) {
                done = 0;
                if (rem[i] > quantum) {
                    t += quantum;
                    rem[i] -= quantum;
                    printf(" | P%d | %d", i+1, t);
                } else {
                    t += rem[i];
                    wt[i] = t - BT[i];
                    rem[i] = 0;
                    printf(" | P%d | %d", i+1, t);
                }
            }
        }
        printf("\n");
    } while (!done);

    float total_wt = 0, total_tat = 0;
    printf("\nPROCESS\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        tat[i] = BT[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", i+1, BT[i], wt[i], tat[i]);
    }
    printf("\nAvg WT: %.2f", total_wt/n);
    printf("\nAvg TAT: %.2f\n", total_tat/n);
    return 0;
}
