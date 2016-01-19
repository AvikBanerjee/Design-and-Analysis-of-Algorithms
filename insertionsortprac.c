#include<stdio.h>
int arr[100], n;
void insertionsort()
{
    int i, temp, j;
    for(i=1; i<n; i++)
    {
        temp=arr[i];
        for(j=i-1; j>=0 && arr[j]>temp; j--)
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=temp;
    }
}
void main()
{
    int i;
    printf("\nEnter the number of elements:");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("\nEnter element %d:", i+1);
        scanf("%d", &arr[i]);
    }
    insertionsort();
    printf("\nThe sorted array is:");
    for(i=0; i<n; i++)
        printf("\n%d", arr[i]);
}
