#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    int time_hour, time_minutes;
    double measure;
    if ((fptr = fopen("simpledb.dat", "w+")) == NULL)
    {
        printf("\nFile could not be opened, exiting program.\n");
    }
    else
    {
        while(1)
        {
            do
            {
                printf("\nEnter the hours of the current time (0-23)  [Enter -1 to exit]"); 
                scanf("%d",&time_hour);
                if (time_hour == -1)
                {
                    printf("\nProgram exitted.");
                    exit(EXIT_SUCCESS);
                }
                if (time_hour>23 || time_hour<0)
                {
                    printf("\nError input. Try again.");
                }
                
            }while(!(time_hour<24 && time_hour>=0));

            do
            {
                printf("\nEnter the minutes of the current time (00-59):"); 
                scanf("%d",&time_minutes);
                if (time_minutes>59 || time_minutes<0)
                {
                    printf("\nError input. Try again.");
                }
            }while(time_minutes>59 || time_minutes<0);
        
            
            printf("\nEnter the measurement value as a real number:");
            scanf("%lf",&measure);
        
            fprintf(fptr,"%d\t%d\t%.3f\n",time_hour,time_minutes, measure);
        }        
    }
    fclose(fptr);
    return 0; 
}