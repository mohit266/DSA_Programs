#include<stdio.h>

void main()
{
    int i,j,MIN;
    int var[30];
    int n;
    printf("Enter number of variable :");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        printf("Enter values var[%d]:",i);
        scanf("%d",&var[i]);
    }

    printf("Values are :");
    for(i=1;i<=n;i++)
    {
        printf("%d, ",var[i]);
    }
    printf("\n");

    printf("Sorted values are : ");
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
           if (var[i] > var[j])
            {
                MIN = var[i];
                var[i] = var[j];
                var[j] = MIN;
            } 
        }
        printf("%d, ",var[i]);
    }
    printf("\n");    
}

