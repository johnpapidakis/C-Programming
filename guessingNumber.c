#include <stdio.h>
#include <stdlib.h>
#define inputInt(x) scanf(" %d",&x)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)


int main()
{
    int num1,num2,guess;
    printf("Enter two numbers to initialise range:\n");
    
    printf("Number 1: ");
    inputInt(num1);

    printf("Number 2: ");
    inputInt(num2);
    
    int max=MAX(num1,num2);
    int min=MIN(num1,num2);
    
    printf("Guess the number that I am thinking  within the initialised range:\n");
    inputInt(guess);

    int randomNum;
    randomNum=rand() % (max - min + 1) + min;

    int try=1;
    while (randomNum!=guess)
    {

        if (guess<randomNum)
        {
            printf("The correct number is bigger.\n");
        }
        else
        {
            printf("The correct number is smaller.\n");
        }
        inputInt(guess);
        try++;
    }

    printf("Well Done. You found the number in %d tries.",try);
    return 0;    
}