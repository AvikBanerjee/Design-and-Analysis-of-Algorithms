#include<stdio.h>
int arr[100];
int minimum(int i, int n)
{
    int j, min;
    min=i;
    for(j=i; j<n; j++)
    {
        if(arr[j]<arr[min])
            min=j;
    }
    return min;
}
void selectionsort(int n)
{
    int i, temp, m;
    for(i=0; i<n-1; i++)
    {
        m=minimum(i, n);
        temp=arr[i];
        arr[i]=arr[m];
        arr[m]=temp;

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
    selectionsort(n);
    printf("\nThe sorted array is:");
    for(i=0; i<n; i++)
    {
        printf("\n%d", arr[i]);
    }
}
