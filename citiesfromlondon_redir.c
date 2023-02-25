#include <stdio.h>
int main()
{
    int distance;
    char cityName[40];
        while (!feof(stdin))
        {
            scanf("%d %s",&distance,cityName);
            if (distance>100)
            {
                printf("%d %s\n",distance,cityName);
            }
            else 
            {
                continue;
            }  
        }   
    return 0;
}


