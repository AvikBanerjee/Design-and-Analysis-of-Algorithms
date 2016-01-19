#include<stdio.h>
int arr[100], heapsize, length;
void maxheapify(i)
{
    int largest, l, r, temp;
    l=2*i;
    r=2*i+1;
    if(l<=heapsize && arr[l]>arr[i])
        largest=l;
    else
        largest=i;
    if(r<=heapsize && arr[r]>arr[largest])
        largest=r;
    if(largest!=i)
    {
        temp=arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;
        maxheapify(largest);
    }
}
void buildmaxheap()
{
    int i;
    heapsize=length;
    for(i=length/2; i>=1; i--)
        maxheapify(i);
}
void heapsort()
{
    int i, temp;
    buildmaxheap();
    for(i=length; i>=2; i--)
    {
       temp=arr[1];
       arr[1]=arr[i];
       arr[i]=temp;
       heapsize--;
       maxheapify(1);
    }
}
void main()
{
    int i;
    printf("\nEnter the number of elements:");
    scanf("%d", &length);
    for(i=1; i<=length; i++)
    {
        printf("\nEnter element %d:", i);
        scanf("%d", &arr[i]);
    }
    heapsort();
    for(i=1; i<=length; i++)
    {
        printf("\n%d", arr[i]);
    }
}
