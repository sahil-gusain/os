#include<stdio.h>
struct FCFS{
 	int AT,BT,CT,TAT,WT,RT;
 };
 int min(struct FCFS process[],int grant[],int n)
 {int m=999;
      for(int  i=0;i<n;i++)
      {
      		if(grant[i]==0);
      		m=i;
      		}
     for(int i=0;i<n;i++)
     {
     		if(process[i].AT<process[m].AT && grant[m]==0)
     		m=i;
     		}
     		grant[m]=1;
     		return m;
    }
     		
 int main()
 {
    int n;
    printf("enter the no of process\n");
    scanf("%d",&n);
    struct FCFS process[n];
    int grant[n];
    for(int i=0;i<n;i++)
    {
        grant[i]=0;
        }
    for(int i=0;i<n;i++)
    {
         printf("enter the Arrival time of process\n",i+1);
         scanf("%d",&(process[i].BT));
         printf("enter the Burst time of process\n",i+1);
         scanf("%d",&(process[i].BT));
    }
    for(int i=0;i<n;i++)
    {
        int j=0;
        int m=min(process,grant,n);
        if(j<process[m].AT) j=process[m].AT;
        process[m].RT=j;
        process[m].CT=j+process[m].BT;
        process[m].TAT=process[m].CT-process[m].AT;
        process[m].WT=process[m].TAT-process[m].BT;
    }
    int sum1=0;
    int sum2=0;
    float avgTAT,avgWT;
    for(int i=0;i<n;i++)
    {
       sum1+= process[i].TAT;
        sum2+= process[i].WT;
    }
    printf("AVERAGE TAT %d  \n",sum1/n);
      printf("AVERAGE WT %d  \n",sum2/n);
   }
