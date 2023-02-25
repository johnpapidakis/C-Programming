#include <stdio.h>
#include <string.h>
void stringDelete(char [],int);
int main()
{
    char word[25];//initialising array to save the word input
    int position;//initialising variable that will obtain position of each array element
    printf("\nType in the word and press Enter:  ");//ask to input word
    scanf("%s",word);
    printf("\nType in the position of the character to be deleted:  ");//ask to input the letter position that will be deleted
    scanf("%d",&position);
    printf("\nOriginal word = %s",word);//prints the initial word
    stringDelete(word,position);
    printf("\nModified word = %s",word);//prints modified word
    return 0;
}
void stringDelete(char word[],int position)//stringDelete function used to delete the charcter from the string
{
    int wordLength = strlen(word);//initialising variable that has the length of the word input
    //// i -- index variable that displays the position of each array element
    ///  wordLength -- index variable that dispalys the the length of the arrray
    for(int i = position-1; i<wordLength; i++)
    {
        word[i]=word[i+1];//shifting element of the string
    }
}