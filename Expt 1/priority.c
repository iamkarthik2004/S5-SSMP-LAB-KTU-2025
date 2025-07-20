/*SS LAB - EXPT 1
(iii) PRIORITY
*/


#include <stdio.h>
int main(){
	int n;
	float avgwt=0, avgtat=0;
	int wtTot=0, tatTot=0;
	
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	int bt[n], wt[n], tat[n], pid[n], priority[n];
	
	//Burst Time Input
	printf("Enter the Burst Time and Priority for each process: \n");
	for(int i=0; i<n; i++){
	pid[i] = i+1;
	printf("Burst time of Process P%d: ", pid[i]);
	scanf("%d", &bt[i]);
	printf("Priority of Process P%d: ", pid[i]);
	scanf("%d", &priority[i]);
	}
	
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(priority[i] > priority[j])
			{	
				//Swap Burst Time
				int temp = bt[i];
				bt[i] = bt[j];
				bt[j] = temp;
				
				//Swap Process ID
				temp = pid[i];
				pid[i] = pid[j];
				pid[j] = temp;
				
				//Swap Prioriy
				temp = priority[i];
				priority[i] = priority[j];
				priority[j] = temp;
			}
		}	
	}
	
	
	wt[0] = 0;
	for(int i=1; i<n; i++){
	wt[i] = wt[i-1] + bt[i-1];
	}
	
	
	for(int i=0; i<n; i++){
	tat[i] = bt[i] + wt[i];
	}
	
	printf("\n");
	
	printf("\nPROCESS ID\tBURST TIME\tPRIORITY\tWAITING TIME\tTURNAROUND TIME\n");
	for(int i=0; i<n; i++){
	printf("P%d   ", pid[i]);
	printf("\t\t%d", bt[i]);
	printf("\t\t%d", priority[i]);
	printf("\t\t%d", wt[i]);
	printf("\t\t%d", tat[i]);
	printf("\n");
	}
	
	
	//Total wt and tat
	for(int i=0; i<n; i++){
	tatTot += tat[i];
	wtTot += wt[i];
	}
	
	avgwt = (float)wtTot/n;
	avgtat = (float)tatTot/n;
	
	printf("\nAverage Waiting Time: %0.2f", avgwt);
	printf("\nAverage Turnaround Time: %0.2f", avgtat);
	
	printf("\n");
	
	printf("\nGantt Chart\n");
	for(int i=0; i<n; i++){
	printf("   P%d   ", pid[i]);
	}
	
	printf("\n");
    	
    	printf("0");
    	for(int i=0; i<n; i++){
    	printf("      %d", tat[i]);
    	}
	
	printf("\n");
	

	return 0;	 
}

