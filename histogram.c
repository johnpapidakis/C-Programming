#include <stdio.h>
#define arrayLength 10

void levelCheck(int,int,int[]);
int main()
{
    int main[arrayLength];
    int max=0; // Min and max will start at 0 anyway
    int min=0;
  
    printf("Please enter 10 numbers:\n");
    for (int i = 0; i < arrayLength; i++)
    {
        scanf("%d",&main[i]);
		if(main[i] > max) 
        { 
            max = main[i]; 
        } 
        // Check if new value is the max
		if(main[i] < min) 
        { 
            min = main[i]; 
        } 
        // Check if new value is the min
    }

	levelCheck(min, max, main);
    return 0;
}

void levelCheck(int min,int max, int main[]) // One less parameter than before since I have min and max
{
    for (int level = max; level >= min; level--)
    {
		if(level == 0) 
        { 
            continue;
        } 
        // Do nothing when 0 level
        for (int j = 0; j < arrayLength; j++)
        {
            if(main[j]>0 && level>0 && main[j]>=level) 
            { 
                printf("* ");
            } 
            // If this is a positive number, in a positive level, i print accordingly
			
            else if(main[j]<0 && level<0 && main[j]<=level) 
            { 
                printf("* ");
            } 
            //Similar thing with negative numbers
			else { printf("  ");}
        }
        printf("\n"); 
    }
}
