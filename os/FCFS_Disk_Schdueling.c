#include<stdio.h>
#include<math.h>
//FCFS SCHEDULING DISK SCHEDULING
int main()
{
   int n,seek_count=0,i,time;
   printf("enter the total size of  Sequence\n ");
   scanf("%d",&n);
   int seq[n];
   printf("enter the sequence\n");
   for(i=0;i<n;i++) scanf("%d",&seq[i]);
   int head;
   printf("enter current head\n");
   scanf("%d",&head);
   for( i=0;i<n;i++)
   {
       seek_count+=fabs(head - seq[i]);
       head=seq[i];
   }
   printf("enter ")
   printf("Total seek time: %d\n",seek_count);
}
//176 79 34 60 92 11 41 114

