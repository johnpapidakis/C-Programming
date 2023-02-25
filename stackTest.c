#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


struct stackNode 
{
    int nodeData;
    struct stackNode *nextPtr;
};
typedef struct stackNode stack;
stack *top=NULL;



int isEmpty(stack *top);
void push(int inputInt);
void printStack();

int isEmpty(stack *top)
{
    if(top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int inputInt)
{
    stack *new;
    new = (struct stackNode*)malloc(sizeof(struct stackNode));
    
    new->nodeData = inputInt; 
    

    new->nextPtr = top; 
    
    top=new;
}

int pop()
{
    if (isEmpty(top)) 
    {
        return 0;
    } 
    else
    {
        struct stackNode *temp;
        int popValue;

        temp = top;             
        popValue = top->nodeData;  
        top = top->nextPtr;

        free(temp);               
        return popValue;
    }
}

void printStack()
{
    if (isEmpty(top)) 
    {
        printf("\nStack is empty\n");
    } 
    else
    {
        stack *temp = top;   
        printf("\n");
        while (temp->nextPtr != NULL) 
        {
            printf("%d--->", temp->nodeData);
            temp = temp->nextPtr;
        }
        printf("%d--->NULL\n\n", temp->nodeData);
    }
}


int main()
{
    int inputInt,option; 
    
    while(1)
    {
        printf("\nEnter\n1. push\n2. pop\n3. quit\n");
        scanf("%d",&option);
        
        if(option==1)
        {
            printf("push a value: ");
            scanf("%d",&inputInt);
            push(inputInt);
            printStack();
        }
        else if(option==2)
        {
            pop();
            printStack();
        }
        else if(option==3)
        {
            break;
        }
        else 
        {
            printf("\nInvalid input. Try again. \n");
        }
    }
    return 0;
}

