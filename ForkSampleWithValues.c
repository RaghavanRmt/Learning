#include<stdio.h>
#include<unistd.h>

int main()
{
	int iValue = 1;
	int iPID = 0;

	iPID = fork();

	if(iPID)
	{
		iValue = 10;
		printf("\r\nParent process iValue: %d process ID: %d child ID: %d", iValue, getpid(),iPID);
		wait();
	}
	else
	{
		iValue--;
		printf("\r\nChild process iValue: %d parent ID: %d child ID: %d", iValue, getppid(), getpid());
	}

	return 0;
}