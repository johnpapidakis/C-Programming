#include <stdio.h>
void leftTriangle(int size, char c)
{
    for (int i = 0; i <size; i++)
    {
        for (int j = size-i; j <=size ; j++)
        {
            printf(" %c",c);
        }
        printf("\n");     
    }
}
void square(int size, char c)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf(" %c", c);
        }
        printf("\n");        
    }
}
void rightTriangle(int size,char c)
{
    for (int i = 0; i < size; i++)
    {
        for (int j =0 ; j < size; j++)
        {
            if (j<i)
            {
                printf("  ");
            }
            else
            {
                printf(" %c",c);
            }   
        }  
        printf("\n");
    }
}
