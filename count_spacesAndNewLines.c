#include <stdio.h>
int main()
{
    char txtInput;
    int spaceCount = 0;
    int lineCount=0;
    printf("Please input text. Press [ctrl-D] to terminate.\n");
    while (txtInput!=EOF)
    {
        txtInput=getchar();
        if (txtInput==(' '))
        {
            spaceCount++;
        }
        else if (txtInput==('\n'))
        {
            lineCount++;
        }           
    }
    printf("\nThe number of spaces in your text are %d\n",spaceCount);
    printf("The number of new lines in your text are %d",lineCount);
    return 0;
}