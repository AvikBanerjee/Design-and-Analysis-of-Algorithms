#include<stdio.h>
typedef struct activity
{
    int start, finish;
    int index;
}act;
void main()
{
    act arr[100], temp;
    int n, i, j, solution[100], t;
    printf("\nEnter the number of activities:");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        printf("\nEnter the starting time fo activity %d:", i);
        scanf("%d", &arr[i].start);
        printf("\nEnter the finishing time of activity %d:", i);
        scanf("%d", &arr[i].finish);
        arr[i].index=i;
    }
    for(i=1; i<n-1; i++)
    {
        for(j=1; j<=n-i-1; j++)
        {
            if(arr[j].finish>arr[j+1].finish)
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    t=1;
    j=arr[1].finish;
    solution[t++]=arr[1].index;
    for(i=2; i<=n; i++)
    {
        if(arr[i].start>=j)
        {
            solution[t++]=arr[i].index;
            j=arr[i].finish;
        }
    }
    while(--t)
    {
        printf("\n%d", solution[t]);
    }
}
