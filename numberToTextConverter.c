#include <stdio.h>
#include <ctype.h>
int main()
{
    char digitArray[9][15]={"One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    char tenArray[9][15]={"Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    char decArray[9][15]={"Ten","Twenty","Thirty","Fourty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    int number;
    
    printf("\nEnter an integer from 1 - 99:   ");
    char digitChar1 = getchar();
    char digitChar2 = getchar();

    int digit1 = digitChar1 - '0';
    int digit2 = digitChar2 - '0';

    if (isdigit(digitChar2)==0)
    {
        printf("%s\n",digitArray[digit1-1]);
    }
    else if (digit1==1 && digit2>0 && digit2<10)
    {
        printf("%s\n",tenArray[digit2-1]);
    }
    else if (digit2==0 && digit1>0 && digit1<10)
    {
        printf("%s\n",decArray[digit1-1]);
    }
    else if (digit1>1 && digit1<10 && digit2>1 && digit2<10)
    {
        printf("%s %s\n",decArray[digit1-1],digitArray[digit2-1]);
    }
    return 0;
}
