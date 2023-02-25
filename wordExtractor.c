#include <stdio.h>
#include <string.h>
int main()
{
    char list[250]; 
    printf("\nEnter a list of words separated by commas:\n");
    fgets(list , sizeof(list), stdin);
    char *ptr;
    ptr = strtok(list, ", ");
    while (ptr != NULL)
    {
        printf("%s\n", ptr); 
        ptr = strtok(NULL, ", ");  
    }
    return 0;
}

