#include <stdio.h>
#define ADDITION(x,y) x+y
#define DEVISION(x,y) x/y
#define SUBTRACTION(x,y) x-y
#define MULTIPLICATION(x,y) x*y

int main()
{
    char opt;
    int num1,num2;
    float result;
    do
    { 
        printf("\nChoose an operator ( + , - , * , / ) or enter [ctrl]-C to terminate: \n");
        scanf (" %c",&opt);
 
        printf ("\nEnter the first number:\n");
        scanf(" %d",&num1); 

        printf ("Enter the second number:\n"); 
        scanf (" %d",&num2);

        if (opt=='+')
        {
            result=ADDITION(num1,num2);
            printf ("\n %d + %d = %.2f\n",num1,num2,result);
        }
        else if (opt=='-')
        {
            result=SUBTRACTION(num1,num2);
            printf ("\n %d - %d = %.2f\n",num1,num2,result);
        }
        else if (opt=='*')
        {
            result=MULTIPLICATION(num1,num2);
            printf ("\n %d * %d = %.2f\n",num1,num2,result);
        }
        else if (opt=='/' && num2!=0)
        {
            result= (float) DEVISION(num1,num2);
            printf ("\n %d / %d = %.2f \n",num1,num2,result);
        }
        else if (opt=='/' && num2==0)
        {
            printf ("\nDivisor cannot be zero.\n");
        }
        else
        {
            printf("\nError Input. Please try again.\n");
        }
    }while (1);  
    return 0;
}