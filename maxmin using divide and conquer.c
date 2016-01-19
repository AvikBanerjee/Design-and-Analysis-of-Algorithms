#include<stdio.h>
int arr[20], max , min;
void maxmin(int lo, int hi)
{
    int mid, max1, min1;
    if(lo==hi)
        max=min=arr[lo];
    else if(lo==hi-1)
    {
        if(arr[lo]<arr[hi])
        {
            max=arr[hi];
            min=arr[lo];
        }
        else
        {
            max=arr[lo];
            min=arr[hi];
        }
    }
    else
    {
        mid=(lo+hi)/2;
        maxmin(lo, mid);
        max1=max;
        min1=min;
        maxmin(mid+1, hi);
        if(max<max1)
            max=max1;
        if(min>min1)
            min=min1;
    }

}
void main()
{
    int n, i, j;
    printf("\nEnter the number of elements:");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("\nEnter element %d:", i+1);
        scanf("%d", &arr[i]);
    }
    maxmin(0, n-1);
    printf("\nMax= %d\nMin= %d", max, min);
}

