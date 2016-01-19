#include<stdio.h>
void main()
{
    int adja[10][10], cost[10][10], i, j, k, n;
    printf("\nEnter the number of vertices:");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf("\nEnter the cost of edge (%d, %d):", i, j);
            scanf("%d", &adja[i][j]);
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            cost[i][j]=adja[i][j];
    }
    for(k=1; k<=n; k++)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(cost[i][j]>cost[i][k]+cost[k][j])
                    cost[i][j]=cost[i][k] + cost[k][j];
            }
        }
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n;j++)
            {
                printf("%d\t", cost[i][j]);
            }
            printf("\n");
        }
    }
}
