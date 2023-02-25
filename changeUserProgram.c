#include <stdio.h>
#include <unistd.h> /* Necessary because exec() function */ 
#include <errno.h> /* Necessary because errno value used */ 
#include <stdlib.h> /* Necessary for exit() */
#include <string.h> /* Necessary for strerror() */

void error(char *msg)
{ 
    fprintf(stderr, "%s: %s\n", msg, strerror(errno)); 
    exit(1);
} 
    

int main (int argc, char *argv[])
{ 
    char *my_env[]={"USER=johnpapidakis",NULL};  
    /*The last item must be NULL */ 
    if (execle("changeUserInfo","changeUserInfo",  "ECS501U", NULL, my_env) == -1)
        error("Cannot run chnageUserInfo"); 
}