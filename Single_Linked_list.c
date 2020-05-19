//  Implementation of Single Linked List.

#include<stdio.h>
#include<stdlib.h>

void append(void);
void add_at_begin(void);
void add_at_after(void);
int length(void);
void display(void);
void delete(void);
void swap_node(void);
void reverse_list(void);

struct node{
    int data;
    struct node* link;
};

struct node* root = NULL;
int len;

void main()
{
    int ch;

    while(1)
    {
        printf("Single Linked List Operations \n");
        printf("1.Append\n");
        printf("2.Add at begin\n");
        printf("3.Add at after\n");
        printf("4.Length\n");
        printf("5.Display\n");
        printf("6.Delete\n");
        printf("7.Swap Adjacent nodes\n");
        printf("8.Reverse the list\n");
        printf("9.Quit\n");

        printf("Enter your choice : ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1:
                append();
                break;
            
            case 2:
                add_at_begin();
                break;

            case 3:
                add_at_after();
                break;
            
            case 4:
                len = length();
                printf("Length of list is : %d\n\n",len);
                break;
            
            case 5:
                display();
                break;
            
            case 6:
                delete();
                break;

            case 7:
                swap_node();
                break;
            
            case 8:
                reverse_list();
                break;

            case 9:
                exit(10);
                
            default:
                printf("Invalid choice !!! Please enter valid input \n");
                break;
        }
    }
}

void append()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter the node value : ");
    scanf("%d",&temp->data);
    temp->link = NULL;

    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node* p;
        p = root;
        while(p->link!=NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}

void add_at_begin()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter the value of node : ");
    scanf("%d",&temp->data);
    temp->link = NULL;

    temp->link = root;
    root = temp;

}

void add_at_after()
{
    int i = 1,loc;
    struct node* temp, *p;

    printf("Enter the location where you want to add the node : ");
    scanf("%d",&loc);

    if(loc > length())
    {
        printf("Invalid location");
    }
    else
    {
        p = root;
        while(i<loc)
        {
            p = p->link;
            i++;
        }
        temp = (struct node*)malloc(sizeof(struct node));

        printf("Enter the node value : ");
        scanf("%d",&temp->data);
        temp->link = NULL;

        temp->link = p->link;
        p->link = temp;

    }
    
}

int length()
{
    int count = 0;
    struct node* temp;

    temp = root;

    while(temp != NULL)
    {
        count++;
        temp = temp->link;
    }
    return count;
}

void display()
{
    struct node* temp;

    temp = root;

    if(temp == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d-->",temp->data);
            temp = temp->link;
        }
        printf("\n\n");
    }
    
}

void delete()
{

    int i=1,loc;
    struct node* temp;

    printf("Enter the location of node which you want to delete :");
    scanf("%d",&loc);

    if(loc > length())
    {
        printf("Invalid location \n");
    }
    else if(loc == 1)
    {
        temp = root;
        root = temp->link;

        temp->link = NULL;

        free(temp);
    }
    else
    {
        struct node* p = root, *q;
        int i = 1;
        while(i<loc-1)
        {
            p = p->link;
            i++;
        }
        q = p->link;
        p->link = q->link;
        q->link = NULL;
        free(q);
    }   
}

void swap_node()
{
    struct node* temp, *r, *q;
    int i = 1,loc;

    printf("Enter the location of node : ");
    scanf("%d",&loc);

    temp = root;

    while(i<loc-1)
    {
        temp = temp->link;
        i++;
    }
    q = temp->link;
    r = q->link;
    q->link = r->link;
    r->link = q;
    temp->link = r;

}

void reverse_list()
{
    struct node *p, *q;
    int i,j,k,temp=0;

    len = length();

    i = 0;
    j = len-1;
    p = q = root;

    while(i<j)
    {
        k=0;
        while(k<j)
        {
            q = q->link;
            k++;
        }

        temp = p->data;
        p->data = q->data;
        q->data = temp;
        i++;
        j--;
        p = p->link;
        q = root;
    }
}