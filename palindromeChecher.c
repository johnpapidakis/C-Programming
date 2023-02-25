#include <stdio.h>
int main()
{
    int length = 5;
    char letters[length];
    int flag = 0 ;   
    int count=0;
   printf("\nEnter a word with 5 letters:\n");
    while (count < length) 
    {
        letters[count] = getchar(); 
        count++;
    }

    for(int i=0; i<length; i++)
    {
        if (letters[i]!=letters[length-i-1])
        {
            flag=1;
        }    
    }
   
    if (flag) 
    {
        printf("This is not a palindrome.");   
    }    
    else
    {
        printf("This word is a palindrome.");
    }
    return 0;
}