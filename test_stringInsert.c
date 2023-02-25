#include <stdio.h>
#include <string.h>
void stringInsert(char str[], char c, int position);//function prototype for stringInsert
/*
    str[]  --  array to save string characters
    c  --  character that will be inserted
    position  -- position of the character that will be inserted
*/
int main()
{
    char str[50];
    char c;
    int position;
    printf("\nType in the word and press Enter:  ");
    scanf("%s",str);
    
    
    //gets(str);
    //if i use scanf i have to close the scanf before i move to a different scanf like scanf("%c",&c);
    //or use while((c =  getchar()) != '\n' && c != EOF); to fill all the array values and close the scanf
   
    printf("\nType the character to be inserted: ");
    scanf(" %c",&c);
  
    printf("\nType in the position of the character to be inserted:  ");
    scanf("%d",&position);
    
    while(position > strlen(str)+1 || position < 0)//repeat until possition is within the range of the word length 
    {
        printf("\nIncorrect input. Position should be between 0 to length of the word\n");
        printf("\nEnter the position of the character:  ");
        scanf("%d",&position);
    }

    printf("\nOriginal word = %s", str);
    stringInsert(str,c,position);//statement to invoke stringInsert function
    printf("\nModified word = %s\n",str);
    return 0;
}
void stringInsert(char str[], char c, int position)//function used to insert a charcter to string
{
    int strLength = strlen(str);// declaring variable with the length of the str array
    // i -- index variable for the position of the length of the str array
    for (int i = strLength; i>=position-1; i--)
    {
        str[i+1] = str[i];///shifting element of str
    }
    str[position-1] = c;///inserting character at the given position

}