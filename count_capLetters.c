#include <stdio.h>
int main()
{
    printf("Please input text. Press [ctrl-D] to terminate.\n");
    char letter;
    int capitalCount=0;
    while(letter!=EOF)
    {
        letter = getchar();
        if (letter==65 )
        {
            capitalCount++;
        }  
    }
    printf("\nThe number of capital letters in your text are %d\n",capitalCount);
    return 0;
}