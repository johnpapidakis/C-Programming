#include <stdio.h>
int main()
{
    FILE *citiesPtr, *hunderdMilesPtr;
    int distance;
    char cityName[40];
    if ((citiesPtr = fopen("cities.txt","r")) == NULL)
    {
        printf("\nFile could not be opened, exiting program.\n");
    }
    else
    {
        hunderdMilesPtr = fopen("citiesOver100Miles.txt","w");
        while (!feof(citiesPtr))
        {
            fscanf(citiesPtr,"%d %s",&distance,cityName);
            if (distance>100)
            {
                if (hunderdMilesPtr == NULL)
                {
                    printf("\nFile could not be created, exiting program.\n");
                }
                else
                {
                    fprintf(hunderdMilesPtr,"%d %s\n",distance,cityName);
                }
            }
            else 
            {
                continue;
            }  
        }
        fclose(hunderdMilesPtr);
    }
    fclose(citiesPtr);
    return 0;
}


