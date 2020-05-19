// Stack implementation using single linked list.

#include<stdio.h>
#include<stdlib.h>

void insert(void);
void pop(void);
void traverse(void);

struct node
{
    int data;
    struct node* link;
};

struct node* top = NULL;

void main()
{

    while(1)
    {
        int ch;
        printf("1.Insert a node in stack.\n");
        printf("2.Pop the item from stack\n");
        printf("3.Traverse the stack items\n");
        printf("4.Quit\n");

        printf("Enter your choice : ");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            insert();
            break;
        
        case 2:
            pop();
            break;
        
        case 3:
            traverse();
            break;

        case 4:
            exit(10);
            break;
        
        default:
            printf("Invalid Choice!!");
            break;
        }
    }
}

void insert()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter the node value : ");
    scanf("%d",&temp->data);
    temp->link = top;

    top = temp;    
}

void pop()
{
    struct node* temp;

    if(top==NULL)
    {
        printf("Stack is Empty");
    }    
    else
    {
        temp = top;
        printf("%d is deleted \n",temp->data);
        top = top->link;
        temp->link = NULL;
        free(temp);
    }
}

void traverse()
{
    struct node* temp;

    if(top==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        temp = top;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp = temp->link;
        }
    }
}