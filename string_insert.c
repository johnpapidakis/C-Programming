#include<stdio.h>//for standared input and output
#include<string.h>//for string function


void stringInsert(char str[],char c,int pos)
{
    for(int i=(strlen(str));i>=pos;i--)
    {
        str[i+1] = str[i];//shifting element of the string
    }
    str[pos] = c; //inserting character at the given position
}
int main()
{
    char str[100],c;//declaring the string variables

    int pos;//declaring the integer variable

    printf("Type in the word and press Enter: ");//asking for a word from the user as input
    scanf("%s",str);//taking string input

    printf("Type the character to be inserted: ");//asking for the character from the user as input

    int t;
    while((t = getchar()) != '\n' && t != EOF);
    scanf("%c",&c);
    
    
    printf("Type in the position of the character to be inserted: ");//asking position from the user as input
    scanf("%d",&pos);//taking integer input
    
    if(pos >= strlen(str))//cheascking position is within range or not
    {
        printf("\n\t\tIncorrect position! Position must be between 0 to length of the word\n\n");/*if not then print error*/
        return 0;//returning zero
    }
    printf("\nOriginal word : %s\n", str);//printing original value of the string
    stringInsert(str,c,pos);//calling stringInsert function
    printf("Modified word : %s1\n",str);//printing Modified value of the string


    return 0;//retuning zero
}

