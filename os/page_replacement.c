#include<stdio.h>

int main()
{
    int n,p;
    printf("enter the total  length of string\n");
    scanf("%d",&n);

    int arr1[n];
    printf("enter the values of the string\n");
    for(int  i=0;i<n;i++)
        scanf("%d",&arr1[i]);

    int hit=0,miss=0;
    printf("enter the total no of page\n");
    scanf("%d",&p);
    int arr[n];
    for(int i=0;i<p;i++) arr[i]=-1;
    int ind=0;
    int flag=0;
    for(int i =0;i<n;i++)
    {
        flag=0;
        for(int j=0;j<3;j++)
        {
            if(arr[j]==arr1[i])
            {
                flag=1;
                break;
            }
        }  
        if(flag==0){
            arr[ind]=arr1[i];
            ind=(ind+1)%3;
            miss++;
        }
        else
        {
            hit++;
        }
        for(int j=0;j<3;j++)
        {
            printf("%d\t",arr[j]);
        }
        printf("\n");
    }
    printf("hit ratio=  %f\nmiss ratio= %f\n",(float)hit*100/n,(float)miss*100/n);
}
