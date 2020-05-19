#include<stdio.h>
#include<stdlib.h>

void append(void);
void add_at_begin(void);
void add_at_after(void);
int length(void);
void traverse(void);

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;
int len;

void main()
{
    while(1)
    {
        int ch;
        printf("\nDoubly Linked List Operations\n");
        printf("1.Append the node\n");
        printf("2.Add at begin\n");
        printf("3.Add at after\n");
        printf("4.Length\n");
        printf("5.Traverse\n");
        printf("6.Quit\n");

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
            printf("Length of list is : %d",len);
            break;
        
        case 5: 
            traverse();
            break;
        
        case 6:
            exit(10);
            break;

        default:
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
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node* p;
        p = root;
        
        while(p->right!=NULL)
        {
            p = p->right;
        }
        p->right = temp;
        temp->left = p;
    }   
}

void add_at_begin()
{
    struct node* temp;
    
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter the node value : ");
    scanf("%d",&temp->data);
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node* p;
        p = root;
        temp->right = p;
        p->left = temp;
        root = temp;
    }   
}

void add_at_after()
{
    struct node* temp, *p;
    int loc,i=1;

    printf("Enter the location where you want to add the node : ");
    scanf("%d",&loc);

    len = length();
    if(loc>len)
    {
        printf("Invalid location\n");
        printf("list have only %d elements\n",len);
    }
    else
    {    
        temp = (struct node*)malloc(sizeof(struct node));

        printf("Enter the node value : ");
        scanf("%d",&temp->data);
        temp->left = NULL;
        temp->right = NULL;

        p = root;

        while(i<loc)
        {
            p = p->right;
            i++;
        }
        temp->right = p->right;
        p->right->left = temp;
        temp->left = p;
        p->right= temp;
        
    }



}

int length()
{
    struct node* temp;
    int count = 0;

    if(root == NULL)
    {
        return 0;
    }
    else
    {
        temp = root;
        while(temp!=NULL)
        {
            count++;
            temp = temp->right;
        }
        return count;
    }
    
}

void traverse()
{
    struct node* temp;

    if(root == NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp = root;
        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp = temp->right;
        }
        printf("\n\n");
    }
    
}