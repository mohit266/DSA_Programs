#include<stdio.h>
#include<stdlib.h>

void main()
{   
    int n,i,j,temp;
    int *arr;

    printf("Enter size of array:");
    scanf("%d",&n);

    arr = (int *) malloc(sizeof(int) * n);

    for(i=0;i<n;i++)
    {
        printf("Enter the value : ");
        scanf("%d",&arr[i]);
    }

    printf("Values are ");

    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("\nSorted values are ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}