#include<stdio.h>
struct PSNP{
 	int AT,BT,CT,TAT,WT,RT,pri;
 };
  		
int main()
{
    int n;
    printf("enter the no of process\n");
    scanf("%d",&n);
    struct PSNP process[n];
    for(int i=0;i<n;i++)
    {
         printf("enter the Arrival time and burst time of process\n",i+1);
         scanf("%d  %d %d",&(process[i].AT),&(process[i].BT),&(process[i].pri));

    }
    for(int i=0;i<n;i++)
    {
    	for(int j=i+1;j<n;j++)
    	{
    		if(process[i].AT>process[j].AT)
    		{
    			struct PSNP temp = process[i];
    			process[i] = process[j];
    			process[j]=process[i];
			}
		}
	}
    for(int i=0;i+1<n;i++)
    {
        if(process[i].AT==process[i].AT && process[i].pri>process[i+1].pri)
        {
            struct PSNP temp = process[i];
    		process[i] = process[i+1];
    		process[i+1]=temp;
        }
    }
	int j=0;
    for(int i=0;i<n;i++)
    {
        if(j<process[i].AT) j=process[i].AT;
        process[i].RT=j;
        process[i].CT=j+process[i].BT;
        process[i].TAT=process[i].CT-process[i].AT;
        process[i].WT=process[i].TAT-process[i].BT;
        j=process[i].CT;
    }
    for(int i=0;i<n;i++)
    {
    	printf("proces %d \t  AT %d \t BT %d \t CT %d \t WT %d \t TAT %d \t\n",i+1,process[i].AT,process[i].BT,process[i].CT,process[i].WT,process[i].TAT);
	}
    int sum1=0;
    int sum2=0;
    for(int i=0;i<n;i++)
    {
       sum1+= process[i].TAT;
        sum2+= process[i].WT;
    }
    
    printf("AVERAGE TAT %f  \n",(float)sum1/n);
    printf("AVERAGE WT %f  \n",(float)sum2/n);
 }
