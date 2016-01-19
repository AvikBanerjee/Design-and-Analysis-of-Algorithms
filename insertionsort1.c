#include<stdio.h>
void main()
{
    int arr[20], i, j, n, tmep;
    printf("\nEnter the number of elements:");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("\nEnter element %d:", i+1);
        scanf("%d", &arr[i]);
    }
    for(i=1; i<n; i++)
    {
        tmep=arr[i];
        for(j=i-1; j>=0 && arr[j]>tmep; j--)
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=tmep;
    }
    printf("\nThe sorted array is:\n\n");
    for(i=0; i<n; i++)
        printf("\n%d", arr[i]);
}
