#include<stdio.h>
int arr[100], n;
int partition(int lo, int hi)
{
    int pivot, i, j, temp;
    pivot=arr[hi];
    i=lo-1;
    for(j=lo; j<hi; j++)
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
    int i;
    printf("\nEnter the number of elements:");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        printf("\nEnter element %d:", i);
        scanf("%d", &arr[i]);
    }
    quicksort(1, n);
    printf("\nThe sorted array is:");
    for(i=1; i<=n; i++)
        printf("\n%d", arr[i]);
}
