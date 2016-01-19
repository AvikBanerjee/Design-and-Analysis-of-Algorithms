#include<stdio.h>
typedef struct joff
{
    int profit;
    int deadline;
    int index;
}job;
void main()
{
    job arr[100], temp;
    int n, i, j, profit, maxprof, maxin, solution[100], t;
    printf("\nEnter the number of jobs:");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("\nEnter the profit of job %d:", i+1);
        scanf("%d", &arr[i].profit);
        printf("\nEnter the deadline of job %d:", i+1);
        scanf("%d", &arr[i].deadline);
        arr[i].index=i+1;
    }
    for(i=1; i<=n-1; i++)
    {
        for(j=0; j<=n-i-1; j++)
        {
            if(arr[j].deadline>=arr[j+1].deadline)
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(i=0; i<n; i++)
        printf("\n%d", arr[i].deadline);
    profit=0;
    maxprof=arr[0].profit;
    maxin=arr[0].index;
    for(i=1, t=0; i<n; i++)
    {
        if(arr[i-1].deadline==arr[i].deadline)
        {
            if(maxprof<arr[i].profit)
            {
                maxprof=arr[i].profit;
                maxin=arr[i].index;
            }
        }
        else
        {
            profit+=maxprof;
            solution[t++]=maxin;
            maxprof=arr[i].profit;
            maxin=arr[i].index;
        }
    }
    profit+=maxprof;
    solution[t++]=maxin;
    printf("\nThe solution set is:\n");
   for(i=0; i<t; i++)
   {
       printf("\t%d", solution[i]);
   }
    printf("\nThe net profit is:%d", profit);
}
