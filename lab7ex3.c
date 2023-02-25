#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#define MAX 200
typedef struct
{
    int account;
    char firstName[25];
    char lastName[25];
    double balance;
}clientRec;

void addClient(clientRec clientAcc[], FILE *fptr);
void printClient(FILE *fptr);

int main()
{
    FILE *fptr;
    static clientRec clientAcc [MAX] ;
    char fileName[40];
    printf("\nEnter the name of the file you wish to create:\n");
    gets(fileName);
    if ((fptr = fopen(fileName, "w")) == NULL)
    {
        printf("\nFile could not be opened for writing, exiting program.\n");
        return 1;
    }
    else
    {
        addClient(clientAcc, fptr);
        fclose(fptr);
        if ( (fptr = fopen(fileName, "r")) == NULL)
        {
            printf("\nFile could not be opened for reading, exiting program.\n");
            return 1;
        }
        else
        {
            printf("\n\nYou have added the following list of client account details %s:", fileName);
            printClient(fptr);
            fclose(fptr);
        }
    }
    return 0;
}

void addClient(clientRec clientAcc[], FILE *fptr)
{
    int flag, size, i=0;
    char balance[15], account[20];
    printf("\nEnter 0 to add a client record or -1 to finish: "); 
    scanf("%d", &flag);
    while (flag != -1)
    {
        while(getchar() != '\n') 
        {
            continue;
        }
        printf("\nEnter client's account number:\n");
        gets(account);
        clientAcc[i].account = atoi(account);

        printf("\nEnter client's first name:\n");
        gets(clientAcc[i].firstName);

        printf("\nEnter client's last name:\n");
        gets(clientAcc[i].lastName);

        printf("\nEnter client's balance:\n");
        gets(balance);
        clientAcc[i].balance = atof(balance);

        i++;
        printf("\nEnter 0 to add a client record or -1 to finish: "); 
        scanf("%d", &flag);
    }
    size=i;
    for (i = 0; i < size; i++)
    {
        fwrite(&clientAcc[i], sizeof(clientRec), 1, fptr); ////further check
    }
    return; 
}

void printClient(FILE *fptr)
{
    clientRec clientAcc;
    fread(&clientAcc, sizeof(clientRec), 1, fptr);
    while (!feof(fptr))
    { 
        printf("\nThe client's account is: %d ", clientAcc.account);
        printf("\nThe client's first name is: %s ", clientAcc.firstName); 
        printf("\nThe client's last name is: %s ", clientAcc.lastName); 
        printf("\nThe client's balance is: %.2f ", clientAcc.balance); 
        printf("\n");
        fread(&clientAcc, sizeof(clientRec), 1, fptr);
    }
    return;
}