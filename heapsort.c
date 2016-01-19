#include<stdio.h>
int arr[20], heapsize, length;
void maxheapify(int i)
{
    int left, right, largest, temp;
    left=2*i;
    right=2*i+1;
    if(left<=heapsize && arr[left]>arr[i])
        largest=left;
    else
        largest=i;
    if(right<=heapsize && arr[right]>arr[largest])
        largest=right;
    if(largest!=i)
    {
        temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        maxheapify(largest);
    }
}
void buildmaxheap()
{
    int i;
    heapsize=length;
    for(i=(length)/2; i>=0; i--)
    {
        maxheapify(i);
    }
}
void heapsort()
{
    int i, temp;
    buildmaxheap();
    for(i=length; i>=1; i--)
    {
        temp=arr[i];
        arr[i]=arr[0];
        arr[0]=temp;
        heapsize=heapsize-1;
        maxheapify(0);
    }
}
void main()
{
    int n, i;
    printf("\nEnter the number of elements:");
    scanf("%d", &n);
    length=n-1;
    for(i=0; i<n; i++)
    {
        printf("\nEnter element %d:", i+1);
        scanf("%d", &arr[i]);
    }
    heapsort();
    printf("\nThe sorted array is:\n\n");
    for(i=0; i<n; i++)
        printf("\n%d", arr[i]);
}
