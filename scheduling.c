#include<stdio.h>
#include<stdlib.h>

struct process{
	int name;//stores the process name as integer value 
	float burst_time;//the time the process will take in CPU
	float arrival_time;//the time when the process arrives into the queue
	float status;//tell the status of the process whether done or still not done
	//0 for 'in queue' and 1 for 'Done'
};

void display(struct process proc[],int num){
	int i;
	printf("The input process details are as shown below\n");
	printf("Sn\tProcess\tBurst-time\tArrival-time\n");
	for(i=0;i<num;i++){
		printf("%d\tp%d\t%f\t%f\n",i+1,proc[i].name,proc[i].burst_time,proc[i].arrival_time);
		
	}
}

void sort(struct process proc[],int num){
	int i,j;//iterative variables
	struct process temp;//a temp variable od struct process type so swap the entire process all together
	for(i=0;i<num-1;i++)//selection sort 
    {
        for(j=i+1;j<num;j++)
        {
            if(proc[i].arrival_time<proc[j].arrival_time){
				//swap the process with lesser arrival time
                temp=proc[i];
                proc[i]=proc[j];
                proc[j]=temp;
			}
        }
        
 		/*
 		Manual part
        temp=proc[i].burst_time;
        proc[i].burst_time=proc[pos].burst_time;
        proc[pos].burst_time=temp;
 
        temp1=p[i];
        p[i]=p[pos];
        p[pos]=temp1;
        
        temp=proc[i].arrival_time;
        proc[i].arrival_time=proc[pos].arrival_time;
        proc[pos].arrival_time=temp;
        */
    }
    
    display(proc,num);//to check if it works
}


int main(){
	int i;//loop variable
	float arrival,burst,sum=0;
	static int num;//holds number of process
	struct process proc[10];//array of struct to hold multiple propeties of a single process

	printf("Enter the number of process:");
	scanf("%d",&num);
	
	printf("\nNow, enter the data for the %d processes:\n",num);

	//inputting the arrival time and burst time from the user.
	for(i=0;i<num;i++){
		
		proc[i].name=i+1;
		printf("Process p%d\n",proc[i].name);
		
		printf("Burst time:");
		scanf("%f",&burst);
		proc[i].burst_time=burst;
		
		printf("Arrival time:");
		scanf("%f",&arrival);
		proc[i].arrival_time=arrival;
		
		proc[i].status=0;
		sum+=proc[i].burst_time;

		printf("\n");
	} 	
	//output the input pricess details
	display(proc,num);
	
	//sort acc to arrival time
	sort(proc,num);
	
	
}
