/*SS LAB - EXPT 1
(iv) ROUND ROBIN
*/



#include <stdio.h>
void roundRobin(int processes[], int n, int BT[], int quantum){
	int rem_bt[n], wt[n], tat[n];
	for(int i=0; i<n; i++){
	rem_bt[i] = BT[i];
	}
	int t=0;
	
	//Print the Gantt Chart
	
	printf("\nGantt Chart\n");
	printf("0");
	while(1){
		int done=1;
		for(int i=0; i<n; i++){
			if(rem_bt[i]>0){
			done = 0;
				if(rem_bt[i]>quantum){
					t+=quantum;
					rem_bt[i]-=quantum;
					printf("| P%d | %d", processes[i],t);
				}
				else{
					t+=rem_bt[i];
					wt[i]=t-BT[i];
					rem_bt[i]=0;
					printf("| P%d | %d", processes[i],t);
				}
			}
		}
		if(done==1){
			break;
		}
		printf("\n");
		
	}
	
	for(int i=0; i<n; i++){
	tat[i] = BT[i] + wt[i];
	}
	

	
	//Display the  Process Details
	printf("\nPROCESS ID\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
	for(int i=0; i<n; i++){
	printf("%d\t\t", processes[i]);
	printf("%d\t\t", BT[i]);
	printf("%d\t\t", wt[i]);
	printf("%d\t\t", tat[i]);
	printf("\n");
	}
	
	
	//Gantt Chart
	float total_wt=0, total_tat=0;
	
	for(int i=0; i<n; i++){
	total_wt += wt[i];
	total_tat += tat[i];
	}
	
	printf("\nAverage Waiting Time: %0.2f", total_wt/n);
	printf("\nAverage Tunraound TIme: %0.2f", total_tat/n);
	
	printf("\n");
	
	
	
	
	

}

int main(){
	int n, quantum;
	printf("Enter the Number of Processes: ");
	scanf("%d", &n);
	
	int processes[n],BT[n];
	printf("Enter the Bust Time of each processes: \n");
	for(int i=0; i<n; i++){
		processes[i] = i+1;
		printf("P%d: ", i+1);
		scanf("%d", &BT[i]);
	
	}
	
	printf("Enter the quantum: ");
	scanf("%d", &quantum);
	
	roundRobin(processes, n, BT, quantum);
	return 0;
}
