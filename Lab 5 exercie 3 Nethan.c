#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


typedef struct stackNode
{
    int nodeData;
    struct stackNode *next;
}node;

node *new, *head;

void push(int d)
{
    new = (node*) malloc(sizeof(node)); // now, i created a new element (new)
	assert(new != NULL); // need to make sure if i was able to create it
    new->nodeData = d; //set the payload of the stack syntax same as (*new).nodeData = i
    new->next = head; // what used to be the head is not the "next" element (*new).next
    head = new;
}
int pop()
{
    node *temp;
    temp=head;
    int d = temp->nodeData;
    head= new->next;
    free(temp);
    temp=NULL;
    return d;
}
void isEmpty()
{
    if(head==NULL)
    {
        printf("Stack is empty a node can't be removed\n");
    }
    else
    {
        printf("Stack is not empty a node can be removed\n");
    }
}
void printStack()
{
    node *temp;
    temp=head;
    
    while(temp!= NULL)
    {
        printf("%d ", temp->nodeData);
        temp = temp->next;
    }
}

int main()
{
    head = NULL;

    isEmpty();
    push(5);
    int d1 =pop();
    isEmpty();
    push(6);
    isEmpty();
    push(7);
    int d2 =pop();
    push(8);
    push(9);
    printf("%d %d\n", d1, d2);
    isEmpty();
    printStack();
    return 0;
}
