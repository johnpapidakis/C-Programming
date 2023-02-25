#include <stdio.h>

int main()
{
    printf("Enter the size of the triangle's side: ");
    int size;  //initialise variable for the size of the equal sides
    scanf("%d",&size);// user input to set size
    int y =size; //initialise variable equal to the value of size variable 

    /*
        i -- index variable for rows
        j -- index variable for the number of '*' to display
    */

    for (int i = 0; i <y; i++)
    {
        for (int j = y-i; j <=y ; j++)
        {
            printf("* "); //display character '*' on screen
        }
        printf("\n");     //move to next line 
    }
    return 0; 
}