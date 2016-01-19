#include<stdio.h>
typedef struct knap
{
    int index;
    int profit;
    int weight;
    float ppw;
}item;
item arr[100];
int m;
void main()
{
    int i, n, j;
    float profit, solution[100]={0};
    item temp;
    printf("\nEnter the number of items:");
    scanf("%d", &n);
    printf("\nEnter the capacity of the knapsack:");
    scanf("%d", &m);
    for(i=0; i<n; i++)
    {
        arr[i].index=i+1;
        printf("\nEnter profit of item %d:", i+1);
        scanf("%d", &arr[i].profit);
        printf("\nEnter weight of item %d:", i+1);
        scanf("%d", &arr[i].weight);
        arr[i].ppw=(float)arr[i].profit/arr[i].weight;
    }
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j].ppw<arr[j+1].ppw)
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(i=0, profit=0; i<n; i++)
    {
        if(arr[i].weight>m)
            break;
        solution[arr[i].index-1]=1;
        m=m-arr[i].weight;
        profit+=arr[i].profit;
    }
    if(arr[i].weight>m && m!=0)
    {
        solution[arr[i].index-1]=(float)m/arr[i].weight;
        profit+=solution[arr[i].index-1]*arr[i].profit;
    }
    printf("\nThe solution set is:\n\n");
    for(i=0; i<n; i++)
    {
        printf("%f\t", solution[i]);
    }
    printf("\nTotal profit=%f", profit);

}
