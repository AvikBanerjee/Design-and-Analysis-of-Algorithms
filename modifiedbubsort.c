#include<stdio.h>
int arr[100];
void bubblesort(int n)
{
    int i, j, flag, temp;
    for(i=0, flag=0; i<n-1; i++, flag=0)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                flag=1;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        if(flag==0)
            break;
    }
}
void main()
{
    int i, j, n;
    printf("\nEnter the number of elements:");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("\nEnter element %d:", i+1);
        scanf("%d", &arr[i]);
    }
    bubblesort(n);
    printf("\nThe sorted array is:");
    for(i=0; i<n; i++)
    {
        printf("\n%d", arr[i]);
    }
}
