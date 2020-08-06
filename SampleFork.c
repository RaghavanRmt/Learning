#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{ 
  
	int iPID = 0;
    // make two process which run same 
    // program after this instruction 
    iPID = fork(); 
	if(iPID == 0)
	{
		printf("\r\nChild process ID: %d parent ID: %d",getpid(),getppid());
	}
	else
	{
		printf("\r\nParent process ID:%d, child process ID: %d",getpid(),iPID);
	}

	wait();
 
    printf("\r\nHello world!\n"); 
    return 0; 
} 