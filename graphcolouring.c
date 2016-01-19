#include<stdio.h>
int adja[10][10], color[10], n, m;
int checkcolor(int i, int k)
{
    int j;
    for(j=1; j<i; j++)
    {
        if(adja[i][j]==1 && color[j]==k)
            return 0;
    }
    return 1;
}
void graphcolor(int i)
{
    int j, k;
    for(j=1; j<=m; j++)
    {
        if(checkcolor(i, j))
        {
            color[i]=j;
            if(i==n)
                {
                    printf("\nNew Solution:");
                    for(k=1; k<=n; k++)
                        printf("\nVertex %d: Color %d", k, color[k]);
                }
            else
                graphcolor(i+1);
        }
    }
}
void main()
{
    int e, i, x, y;
    printf("\nEnter the number of vertices and edges:");
    scanf("%d%d", &n, &e);
    for(i=1; i<=e; i++)
    {
        printf("\nEnter adjacent vertices:");
        scanf("%d%d", &x, &y);
        adja[x][y]=adja[y][x]=1;
    }
    printf("\nEnter the number of colors:");
    scanf("%d", &m);
    graphcolor(1);
}
