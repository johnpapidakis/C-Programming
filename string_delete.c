#include<stdio.h>//for standared input and output
#include<string.h>//for string function
void stringDelete(char *str,int pos)//stringDelete function used to delete the charcter from the string
{
    for(int i=pos;i<strlen(str);i++)//iterating loop from pos to length of the string
    {
        str[i] = str[i+1];//shifting element of the string
    }
}
int main()//int main function
{
    char str[100];//declaring the string variable
    int pos;//declaring the integer variable
    printf("Type in the word and press Enter: ");//asking for a word from the user as input
    scanf("%s",str);//taking string input
    printf("Type in the position of the character to be deleted: ");//asking position from the user as input
    scanf("%d",&pos);//taking integer input
    if(pos >= strlen(str))//checking position is within range or not
    {
        printf("\n\t\tIncorrect position! Position must be between 0 to length of the word\n\n");/*if not then print error*/
        return 0;//returning zero
    }
    printf("\nOriginal word : %s\n", str);//printing original value of the string
    stringDelete(str,pos);//calling stringDelete function 
    printf("Modified word : %s\n\n", str);//printing Modified value of the string


    return 0;//retuning zero
}
