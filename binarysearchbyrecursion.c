#include<stdio.h>
#include<conio.h>
int arr[100];
int binser(int lo, int hi, int ser)
{
    int mid;
    if(lo>hi)
        return -1;
    mid=(lo+hi)/2;
    if(arr[mid]==ser)
        return mid + 1;
    else if(ser<arr[mid])
        binser(lo, mid-1, ser);
    else if(ser>arr[mid])
        binser(mid+1, hi, ser);


}
void main()
{
    int i, s, pos, n;
    printf("\nEnter the number of elements:");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("\nEnter element %d:", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the value to search:");
    scanf("%d", &s);
    pos=binser(0, n-1, s);
    if(pos==-1)
        printf("Value not found!");
    else
        printf("Value found at %d", pos);

}
