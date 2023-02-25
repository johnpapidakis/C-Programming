#include <stdlib.h>
#include  <stdio.h>
#include  <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


void runChild(void) 
{
    execlp("ls", "ls","-aF","/", NULL);
}

int main(void)
{
    pid_t  pid;
    int status;
    pid = fork();
    if (pid == 0) 
        runChild();
    else 
    {
        wait (&status);
        printf("\nI am still there! My pid is %d\n",getpid());
        printf("\nChild exited with status %d\n",status);
    }

    return 0;
}
