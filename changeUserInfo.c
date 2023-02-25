/* This is the code of changeUser.c */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("\n... Before change: USER=%s\n",getenv("USER"));
    printf("\n... After change : USER=%s\n",argv[1]);

    return 0;
}