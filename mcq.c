#include<stdio.h>

int main() {
    int i;

    char *mystrings[] =
    {
        "Hello",
        "this",
        "is",
        "a",  
        "test"
    };

    char **mypoints[5];

    for(i=0;i<4;i++) mypoints[i]=&mystrings[4-i];
    
    mypoints[0] = &mystrings[2];
    mypoints[4] = &mystrings[0];

    for(i=0; i<5; i++) printf("%s ", *mypoints[i]);

    return 0;
}

