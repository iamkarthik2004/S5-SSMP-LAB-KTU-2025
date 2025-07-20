/*SS LAB - EXPT 1
(i) FCFS
*/

#include <stdio.h>
int main(){
	int n;
	float avgwt=0, avgtat=0;
	int wtTot=0, tatTot=0;
	
	printf("Enter the number of Processes: ");
	scanf("%d", &n);
	int bt[n], wt[n], tat[n];
	
	printf("Enter the Burst Time of each process:\n");
	for(int i=0; i<n; i++){
		printf("P%d: ", i+1);
		scanf("%d", &bt[i]);
	}

	wt[0]=0;
	for(int i=1; i<n; i++){
		wt[i] = wt[i-1] + bt[i-1];
	}
	
	for(int i=0; i<n; i++){
		tat[i] = bt[i] + wt[i];
	}
	
	printf("PROCESS ID\tBurst Time\tWaiting Time\tTurnAround Time\n");
    	for(int i=0; i<n; i++)
    	{
        	printf("P%d:  ",i);
        	printf("\t\t%d",bt[i]);
		printf("\t\t\t%d",wt[i]);
		printf("\t\t%d", tat[i]);
		printf("\n");
    	}
	
	for (int i = 0; i < n; i++) {
        	tatTot += tat[i];
        	wtTot += wt[i];
        }
        
	avgwt = (float)wtTot / n;
    	avgtat = (float)tatTot / n;
    	
    	printf("\nAverage Waiting Time: %0.2f\n", avgwt);
    	printf("Average Turnaround Time: %0.2f\n", avgtat);
    	
    	printf("\nGantt Chart\n");
    	
    	for(int i=0; i<n; i++){
    	printf("   P%d   ", i+1);
    	}
    	
    	printf("\n");
    	
    	printf("0");
    	for(int i=0; i<n; i++){
    	printf("      %d", tat[i]);
    	}
	
	printf("\n");
		
	return 0;	
}
