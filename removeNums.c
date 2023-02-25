#include <stdio.h>
int main()
{
   
    char c;
    
    
    while (!feof(stdin))
        {

            do
            {
                int count=0;
                do
                {
                    c=fgetc(stdin);
                }while(count>28);
                
                printf("\n");
                
            }while (c!='\n');
            
            return 0;
            
        }  
}