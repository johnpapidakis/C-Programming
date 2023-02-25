#include <stdio.h>

int main()
{
    float num;
    float z=0;

    scanf("%f",&num);


    

    while (num <40.0)
    {
        z = num*50.0;
    }
    num = num - 40;
    z = num*75.0+2000.0;
    printf("%f",z);

    
    return 0;
}
