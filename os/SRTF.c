#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

typedef struct srtf
{
    int pid,at,bt,ct,tat,wt,rt,st;
}srtfs;


int main()
{
    int n;
    printf("enter the number of processes : ");
    scanf("%d",&n);
   
   srtfs arr[n];

    int brt[n];
    for(int i=0;i<n;i++)
     {
        scanf("%d %d",&arr[i].at ,&arr[i].bt);
        brt[i] = arr[i].bt;
        arr[i].pid = i+1;
    }

    int prev =0,curr=0,idel =0,completed=0,t_rt=0,t_tat=0,t_wt=0;
float avgtat,avgwt,avgrt,cpu_utilization,throughput;
while(completed!=n)
{
    int min =INT_MAX,index=-1;

    for(int i=0;i<n;i++)
    {
        if(curr>=arr[i].at && brt[i]>0 && min >brt[i])
        {
            min = brt[i];
            index = i;
        }
        if(brt[i] == min && arr[i].at < arr[index].at)
        {
            index = i;
        }
    }

    if(index!=-1)
    {
        if(brt[index] == arr[index].bt)
        {
            if(curr >arr[index].at)
            {
                arr[index].st = curr;
            }
            else 
            arr[index].st = arr[index].at;

              idel =arr[index].st-prev;
        }

        curr++;
        brt[index]--;
        prev = curr;

        if(brt[index] == 0)
        {
            arr[index].ct = curr;
            completed++;  
            arr[index].tat = arr[index].ct - arr[index].at;
            arr[index].wt = arr[index].tat - arr[index].bt;
            arr[index].rt = arr[index].st-arr[index].at;
            t_rt+=arr[index].rt;
            t_tat = arr[index].tat;
            t_wt+= arr[index].wt;
        }

    }
    else curr++;
}

avgrt = (float)t_rt/n;
avgtat =(float)t_tat/n;
avgwt =(float)t_wt/n;
cpu_utilization = (float)(curr-idel)/curr;
throughput = (float)n/curr;

printf("pid  AT  BT  CT  TAT  WT  RT\n");



for(int i=0;i<n;i++)
{   
           printf("%2d  %2d  %2d  %2d  %2d  %2d  %2d\n",arr[i].pid,arr[i].at,arr[i].bt,arr[i].ct,arr[i].tat,arr[i].wt,arr[i].rt);

}
    printf("Average Response Time : %.2f\n",avgrt);
    printf("Average Turnaround Time : %.2f\n",avgtat);
    printf("Average Waiting Time : %.2f\n",avgwt);
    printf("CPU Utilization : %.2f\n",cpu_utilization);
    printf("Throughput : %.2f\n",throughput);

}
