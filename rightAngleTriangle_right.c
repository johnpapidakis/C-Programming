#include <stdio.h>

int main()
{
    printf("Enter the size of the triangle's side: ");
    int size;
    scanf("%d",&size);
    int y =size;
    for (int i = 0; i < y; i++)
    {
        for (int j =0 ; j < y; j++)
        {
            if (j<i)
            {
                printf("  ");
            }
            else
            {
                printf("* ");
            }   
        }  
        printf("\n");
    }
    return 0;
}