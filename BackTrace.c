#include<stdio.h>
#include<unistd.h>
#include<signal.h>


void CreateSegFault(int *in_iData);
void HandleSigSegv(int in_iSigNo);

int main()
{
	signal(SIGSEGV,HandleSigSegv);

	CreateSegFault(NULL);

	return 0;
}

void HandleSigSegv(int in_iSigNo)
{
	void *array[100];
	char **cData;
	size_t size = 0;

	/* get void*'s for all entries on the stack */
	size = backtrace(array, 100);
	backtrace_symbols_fd(array, size, STDERR_FILENO);

	abort();
}

void CreateSegFault(int *in_iData)
{
	*in_iData = 1;
}