#include<stdio.h>
int arr[100], temp[100];
void merge(int lo, int hi)
{
    int mid, i, j, t;
    mid=(lo+hi)/2;
    for(t=i=lo, j=mid+1; i<=mid && j<=hi;)
    {
        if(arr[i]<=arr[j])
        {
            temp[t++]=arr[i];
            i++;
        }
        else if(arr[j]<arr[i])
        {
            temp[t++]=arr[j];
            j++;
        }
    }
    if(i>mid)
    {
        while(j<=hi)
        {
            temp[t++]=arr[j];
            j++;
        }
    }
    else if(j>hi)
    {
        while(i<=mid)
        {
            temp[t++]=arr[i];
            i++;
        }
    }
    for(i=lo; i<=hi; i++)
    {
        arr[i]=temp[i];
    }
}
void mergesort(int lo, int hi)
{
    int mid;
    if(lo<hi)
    {
        mid=(lo+hi)/2;
        mergesort(lo, mid);
        mergesort(mid+1, hi);
        merge(lo, hi);
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
    mergesort(0, n-1);
    printf("\nThe sorted array:\n\n");
    for(i=0; i<n; i++)
        printf("\n%d", arr[i]);
}
