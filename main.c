#include <stdio.h>
#include "shapes.h"
int main()
{
    int size;
    char c;
    printf("Set size of shapes side: ");
    scanf(" %d",&size);
    printf("\nSet character: ");
    scanf(" %c",&c);
    leftTriangle(size,c);
    square(size,c);
    rightTriangle(size,c);
    return 0;
}
