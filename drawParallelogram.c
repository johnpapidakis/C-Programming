#include <stdio.h>
int main()
{
    printf("Enter the size of the side that each triangle and square are going to have: ");
    int size;
    scanf("%d",&size);
    int y = size;
    for (int i = 0; i < 3*y; i++)
    {
        if(i<y)
        {
            for (int j = y-i; j <y ; j++)
            {
                printf("*  ");
            }
            printf("\n");
        }
        else if (i<2*y && y<=i)
        {
            for (int j = y; j < 2*y; j++)
            {
                printf("*  ");
            }
            printf("\n"); 
        }
        else
        {
            for (int j =2*y ; j < 3*y; j++)
            {
                if (j<i)
                {
                    printf("   ");
                }
                else
                {
                    printf("*  ");
                }   
            }  
            printf("\n");
        }        
    }
    return 0;
}