#include<stdio.h>
#include<stdlib.h>

struct process{
	float burst_time;
	float arrival_time;
	float waiting_time;
	float priority;
};

void display(struct process proc[],int num){
	int i;
	printf("The input process details are as shown below\n");
	printf("Sn\tProcess\tBurst-time\tArrival-time\n");
	for(i=0;i<num;i++){
		printf("%d\t p%d\t%f\t%f\n",i+1,i+1,proc[i].burst_time,proc[i].arrival_time);
		
	}
}

int main(){
	int i;//loop variable
	static int num;//holds number of process
	struct process proc[num];//array of struct to hold multiple propeties of a single process
	printf("Enter the number of process:");
	scanf("%d",&num);
	
	printf("\nNow, enter the data for the %d processes:\n",num);
	
	//inputting the arrival time and burst time from the user.
	for(i=0;i<num;i=i+1){
		printf("Enter the p%d's:\n",i+1);
		
		printf("Burst time: ");
		scanf("%f",&proc[i].burst_time);
		
		printf("Arrival time: ");
		scanf("%f",&proc[i].arrival_time);
		
		printf("\n");
			
	} 	
	//output the input pricess details
	display(proc,num);
	
}
