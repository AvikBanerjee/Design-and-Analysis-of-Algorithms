#include<stdio.h>
int arr[100], n;
int findmin(int i)
{
    int min, j, minindex;
    for(j=i, min=arr[i], minindex=i; j<n; j++)
    {
        if(arr[j]<min)
        {
            minindex=j;
            min=arr[j];
        }
    }
    return minindex;
}
void selectionsort()
{
    int i, min, temp;
    for(i=0; i<n; i++)
    {
        min=findmin(i);
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
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
    selectionsort();
    printf("\nThe sorted array is:");
    for(i=0; i<n; i++)
        printf("\n%d", arr[i]);
}
