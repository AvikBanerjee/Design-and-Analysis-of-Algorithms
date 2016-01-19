#include<stdio.h>
int cost[10][10], dist[10], n;
void bellmanford(int v)
{
    int i, j, k, p;
    for(i=1; i<=n; i++)
        dist[i]=cost[v][i];
    for(k=2; k<=n-1; k++)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(i==v)
                    continue;
                if(dist[j]!=1000 && cost[j][i]!=1000 && dist[i]>dist[j]+cost[j][i])
                    dist[i]=dist[j]+cost[j][i];
            }
        }
        printf("\nk=%d", k);
        for(p=1; p<=n; p++)
            printf("\t%d", dist[p]);
    }
}
void main()
{
    int i, j;
    printf("\nEnter the number of vertices:");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf("\nEnter the cost of the path between vertices %d and %d:", i, j);
            scanf("%d", &cost[i][j]);
        }
    }
    bellmanford(1);

}
