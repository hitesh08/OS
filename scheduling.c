#include<stdio.h>
#include<stdlib.h>

struct process{
	float burst_time;
	float arrival_time;
	float waiting_time;
	float priority;
};

void display(struct process proc[],int num,int p[]){
	int i;
	printf("The input process details are as shown below\n");
	printf("Sn\tProcess\tBurst-time\tArrival-time\n");
	for(i=0;i<num;i++){
		printf("%d\t p%d\t%f\t%f\n",i+1,i+1,proc[i].burst_time,proc[i].arrival_time);
		
	}
}

void sort(struct process proc[],int num,int p[]){
	int i,j,pos;
	float temp;
	for(i=0;i<num;i++)
    {
        pos=i;
        for(j=i+1;j<num;j++)
        {
            if(proc[j].burst_time<proc[pos].burst_time)
                pos=j;
        }
 
        temp=proc[i].burst_time;
        proc[i].burst_time=proc[pos].burst_time;
        proc[pos].burst_time=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    display(proc,num,p);
}

int main(){
	int i;//loop variable
	static int num;//holds number of process
	struct process proc[num];//array of struct to hold multiple propeties of a single process
	int p[num];
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
		p[i]=i;
	} 	
	//output the input pricess details
	display(proc,num,p);
	
	//sort acc to busrt time
	sort(proc,num,p);
	
}
