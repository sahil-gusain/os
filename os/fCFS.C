#include<stdio.h>
struct process
{
    int id,at,bt,st,ct,rt,tat,wt;
};
int main(){

    int n;
    printf("enter the no of process\n");
    scanf("%d",&n);
    struct process p[n];
    printf("enter the burst and arrival time \n");
    printf("process    AT   BT\n");
    for(int i=0;i<n;i++)
    {
        printf("p%d:   ",i+1);
        scanf("%d %d",&(p[i].at),&(p[i].bt));
        p[i].id=i+1;
    }
    for(int i=0;i<n;i++)
    {
        for( int j=i+1;j<n;j++)
        {
            if(p[i].at>p[j].at){
                struct process temp;
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
        }
    }
  }
  int ptr=p[0].at,ideal=0;
  for(int i=0;i<n;i++)
  {
    if(p[i].at>ptr)
    {
        ideal+=p[i].at-ptr;
        ptr=p[i].at;
    }
    p[i].st=ptr;
    ptr+=p[i].bt;
    p[i].ct=ptr;
  }
  float totrt,totwt,tottat,cput,thrput;
  printf("\n Process  ST CT RT TAT WT \n");
  for(int i=0;i<n;i++)
  {
    p[i].rt=p[i].st-p[i].at;
    p[i].tat=p[i].ct-p[i].at;
    p[i].wt=p[i].tat-p[i].bt;
    totrt+=p[i].rt;
    totwt+=p[i].wt;
    tottat+=p[i].tat;
    printf("p%d  %d %d %d %d %d\n",p[i].id,p[i].st,p[i].ct,p[i].rt,p[i].tat,p[i].wt);
  }
  cput=((float)(ptr-ideal)/ptr)*100;
  thrput=(float)n/ptr;
  printf("Ideal time:%d\n AvgRT:%f \n AvgTAT=%f\n AVgWT=%f\n Cpu utilization=%f\n throughput=%f",ideal,(totrt/n),(tottat/n),(totwt/n),cput,thrput);
}