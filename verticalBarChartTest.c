#include <stdio.h>
#define arrayLength 10

void levelCheck(int minConst,int maxConst,int level,int main[]);
int main()
{
    printf("Please enter 10 numbers:\n");
  
    int main[arrayLength];
    for (int i = 0; i < arrayLength; i++)
    {
        scanf("%d",&main[i]);
    }

    int max=main[0];
    for (int i = 0; i < arrayLength; i++)
    {
        if(main[i] > max)  
        {  
           max = main[i];   
        }
    }

    int min=main[0];
    for (int i = 0; i < arrayLength; i++)
    {
        if(main[i] < min)  
        {  
           min = main[i];   
        }
    }
    
    const int maxConst=max;
    const int minConst=min;
    int level;

    if(maxConst>=0 && minConst>=0)
    {
        level=maxConst;
        levelCheck(min=0,maxConst,level,main);
    }
    else if(maxConst>0 && minConst<0)
    {
        level=maxConst;
        levelCheck(minConst,maxConst,level,main);
    }  
    else if(maxConst<=0 && minConst<0)
    {      
        level=-1;
        levelCheck(minConst,max=0,level,main);
    }
    return 0;
}

void levelCheck(int minConst,int maxConst,int level, int main[])
{
    for (int i = 0; i < (maxConst-minConst); i++)
    {
        for (int j = 0; j < arrayLength; j++)
        {
            if (main[j]<level && main[j]>=0) //main[]-positive + level above zero
            {
                printf("  ");  
            }
            else if (main[j]>=level && main[j]>0 && level>0 )//main[]-positive + level equal main[]
            {
                printf("* ");
            }
            else if (main[j]<level && main[j]<0 && level>0) //main[]-negative + level above zero
            {
                printf("  ");
            }
            else if (main[j]<=level && main[j]<0 && minConst<=level) //main[]-negative + main[] <= level <  zero
            {
                printf("* ");
            }
            else if (main[j]>level && main[j]>=0 && minConst<=level && level<0) //main[]-positive + main[] < level <  zero
            {
                printf("  ");
            }
            else if (main[j]>level && main[j]<=0 && minConst<=level && level<0) 
            {
                printf("  ");
            }
        }
        level--;
        if (level == 0)
        {
            level--;
        }
        printf("\n"); 
    }
}
