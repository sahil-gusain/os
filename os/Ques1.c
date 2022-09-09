#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{ 
  
  int n;
  printf("enter the size of the array \n");
  scanf("%d",&n);
  int arr[n];
  printf("enter the values of array\n");
  for(int i=0;i<n;i++)
  {
   scanf("%d",&arr[i]);
   }
   int p=fork();
   if(p==0)
    {
      printf("child is printing");
   	for(int i=0;i<n;i++)
        {
           if(arr[i]%2==0) printf("%d\n",arr[i]);
           }
   }
    if(p>0)
    {
      printf("parent is printing ");
   	for(int i=0;i<n;i++)
        {
           if(arr[i]%2!=0) printf("%d\n",arr[i]);
           }
   }
  return 0;
  }
