#include<stdio.h>
int arr[100];
int partition(int lo, int hi)
{
    int pivot, i, j, temp;
    pivot=arr[hi];
    for(i=lo-1, j=lo; j<=hi-1; j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    arr[hi]=arr[i+1];
    arr[i+1]=pivot;
    return i+1;
}
void quicksort(int lo, int hi)
{
    int mid;
    if(lo<hi)
    {
        mid=partition(lo, hi);
        quicksort(lo, mid-1);
        quicksort(mid+1, hi);
    }
}
void main()
{
    int n, i;
    printf("\nEnter the number of elements:");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("\nEnter element %d:", i+1);
        scanf("%d", &arr[i]);
    }
    quicksort(0, n-1);
    printf("\nThe sorted array is:\n\n");
    for(i=0; i<n; i++)
        printf("\n%d", arr[i]);
}
