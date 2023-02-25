#include  <stdio.h>
#include  <sys/types.h>
#include <unistd.h>


void runChild(void) 
{
    printf("\nI am the child! My pid is %d\n",getpid());
}
void  ParentProcess(void)
{
    sleep(5);
     
    printf("\nI am still there! My pid is %d\n",getpid());

}
int main(void)
{
    pid_t  pid;

    pid = fork();
    if (pid == 0) 
        runChild();
    else 
        ParentProcess();

    return 0;
}
