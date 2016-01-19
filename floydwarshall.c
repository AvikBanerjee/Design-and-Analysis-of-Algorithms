#include<stdio.h>
void main()
{
    int cost[10][10], n, i, j, k, p, q;
    printf("\nEnter the number of vertices:");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf("\nEnter the cost of path between vertices %d and %d:", i, j);
            scanf("%d", &cost[i][j]);
        }
    }
    for(k=1; k<=n; k++)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(cost[i][j]>(cost[i][k]+cost[k][j]))
                    cost[i][j]=cost[i][k]+cost[k][j];
            }
        }
        printf("\nStep:\n");
        for(p=1; p<=n; p++)
        {
            for(q=1; q<=n; q++)
                printf("\t%d", cost[p][q]);
            printf("\n");
        }
    }
}
