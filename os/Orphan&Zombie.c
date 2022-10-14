#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	// ZOMBIE PROCESS
	int p =fork();
	if(p!=0){
	    printf("parent process exited\n");
	    sleep(10);
	}
	else{
	printf("Zombie process\n");
	printf("child procces is still running \n ");
	}
	//ORPHAN PROCESS
	//int p =fork();
	//if(p!=0){
	  //  printf("parent process exited\n");
	    //exit(0);
	//}
	//else{
	//printf("Orphan Process\n");
	//printf("child procces is still running \n ");
	//}
}
	
