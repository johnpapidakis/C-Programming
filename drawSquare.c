#include <stdio.h>

int main ()
{
    int size ;
    printf("Enter the size of the square side: ");
    scanf("%d", &size);
    int y =size;
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("*  ");
        }
        printf("\n");        
    }
    return 0;
}