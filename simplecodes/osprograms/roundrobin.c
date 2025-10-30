#include <stdio.h>
int main(){
    int n, q, i, done, p[10], b[10], r[10], w[10]={0}, t=0, tat[10];
    printf("No.of processes: ");
    scanf("%d", &n);
    printf("Burst Time: \n");
    for(i=0; i<n; i++){
        printf("P%d: ", i+1);
        scanf("%d", &b[i]);
        r[i] = b[i];
        p[i] = i+1;
    }
    printf("Quantum: ");
    scanf("%d", &q);
    printf("\nGantt Chart\n0");
    do{
        done=1;
        for(i=0; i<n; i++){
            if(r[i]>0){
                done=0;

                int x = (r[i]>q)?q:r[i];

                r[i]-=x; t+=x;

                if(r[i]==0) w[i]=t-b[i];
                
                printf(" |P%d |%d", p[i], t);
            }
        }
        printf("\n");
    }
    while(!done);
    float tw=0, ta=0;
    printf("\nPID BT WT TAT\n");
    for(i=0; i<n; i++){
        tat[i] = b[i] + w[i];
        tw+=w[i]; ta+=tat[i];
        printf("P%d %d %d %d\n", p[i], b[i], w[i], tat[i]);
    }
    printf("Avg WT: %.2f\nAvg TAT: %.2f\n", tw/n, ta/n);
    return 0;
}
