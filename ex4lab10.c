#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

int score = 0;


void handler(int sig) 
{
    printf("TIME IS UP!!!\n");
    printf("Final score: %d\n", score);
    exit(0);
}

int main() 
{
    int length = 3;
    int time = 20;

    char *str = malloc(sizeof(char) * 100);
    char *rev = malloc(sizeof(char) * 100);

    signal(SIGALRM, handler);

    while (1) 
    {
        printf("Enter a palindrome of %d letters: ", length);
        scanf("%s", str);

        alarm(time);

        for (int i = 0; i < length; i++) 
        {
            rev[i] = str[length - i - 1];
        }

        if (strcmp(str, rev) == 0) 
        {
            score++;
            printf("Correct!\n");
        } else 
        {
            printf("Incorrect!\n");
            printf("Final score: %d\n", score);
            exit(0);
        }

        length++;
        time += 10;
    }

    return 0;
}