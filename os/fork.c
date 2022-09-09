#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{ 
  int p=fork();
  if(p<0){
  printf("error occured");
  exit(1);
  }
  else{
  if(p==0){
   printf("Child %d ",getpid());
   printf("child value %d\n",p);
   }
   else {
   if(p>0){ printf("parent %d ",getpid());
   printf("parent value %d\n",p);
   }
   }
  }
  printf("Hello wrld %d \n",getpid());
  
  return 0;
  }
