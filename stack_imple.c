// Stack implementation using static array.

#include<stdio.h>
#include<stdlib.h>

#define CAPACITY 5
int stack[CAPACITY], top = -1;
void push(int);
void pop(void);
int isFull(void);
int isEmpty(void);
int peek(void);
int traverse(void);

void main()
{

    while(1)
    {
        int ch,item;
        printf("Choose the operation:\n");
        printf("1. Push \n");
        printf("2. pop \n");
        printf("3. peek \n");
        printf("4. Traverse \n");
        printf("5. Quit \n");
        printf("Enter your chocie :");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            printf("Enter element which you want to insert in the stack:");
            scanf("%d",&item);
            push(item);
            break;

        case 2:
            pop();
            break;
        
        case 3:
            peek();
            break;
        
        case 4:
            traverse();
            break;

        case 5:
            exit(10);

        default:
            printf("Invalid choice!! Please enter valid input\n\n");
            break;
        }
    
    }
}
void push(int ele)
{
    if (isFull()){
        printf("-------------Stack is overflow-------------\n");
    }
    else
    {
        top++;
        stack[top] = ele;
        printf("---> %d is inserted \n",ele);
    }
}
int isFull()
{
    if(top == CAPACITY-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void pop()
{
    if (isEmpty())
    {
        printf("-----------Stack is underflow-------------\n");
    }
    else
    {
        printf("---> %d is popped\n",stack[top]);
        stack[top--];
    }
}

int isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int peek()
{
    if(isEmpty())
    {
        printf(" ---------- Stack is underflow-------------\n");
    }
    else
    {
        printf("---> peek element is  : %d \n",stack[top]);
    }
}

int traverse()
{
    int i;
    if(isEmpty())
    {
        printf("---------------Stack is underflow-------------\n");
    }
    else
    {
        printf("---> Elements are :");
        for(i=0;i<=top;i++)
        {
            printf("%d ",stack[i]);
        }
        printf("\n");
    }    
}