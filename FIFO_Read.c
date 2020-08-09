// C program to implement one side of FIFO 
// This side reads first, then reads 
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
int main() 
{ 
	char arr1[80] = {0};
    int fd1; 
  
    // FIFO file path 
    char * myfifo = "/tmp/myfifo"; 
  
	mkfifo(myfifo,0666);

    fd1 = open(myfifo,O_RDONLY);

	read(fd1,arr1,80);

	printf("\r\nData from another process:%s",arr1);

	close(fd1);
	
    return 0; 
} 