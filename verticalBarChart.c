#include <stdio.h>
int main()
{
    printf("Please enter 10 numbers:\n");
    int arrayLength=10;
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
    

    if(maxConst>=0 && minConst>=0)
    {
        int level = max;
        for (int i = 0; i < maxConst; i++)
        {
            for (int j = 0; j < arrayLength; j++)
            {
                if (main[j]<level && main[j]>=0)
                {
                    printf("  ");  
                }
                else if (main[j]>=level && main[j]>=0  )
                {
                    printf("* ");
                }
            }
            level--;
            printf("\n"); 
        }
    }
    


    else if(maxConst>0 && minConst<0)
    {
        int level = max;
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
                else if (main[j]>level && main[j]<0 && minConst<=level && level<0) 
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
    
    else if(maxConst<=0 && minConst<0)
    {
        int level = -1;
        for (int i = 0; i < (-minConst); i++)
        {
            for (int j = 0; j < arrayLength; j++)
            {
                
                if (main[j]<=level && main[j]<0 && minConst<=level) //main[]-negative + main[] <= level <  zero
                {
                    printf("* ");
                }
                else if (main[j]>level && main[j]<=0 && minConst<=level && level<0) 
                {
                    printf("  ");
                }
            }
            level--;
            
            printf("\n"); 
        }
    }

    return 0;
}