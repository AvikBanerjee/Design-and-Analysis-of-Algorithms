#include<stdio.h>
#include<conio.h>
int adja[100][100], n, colour[100], m;
int coltest(int i, int k)
{
    int j;
    for(j=1; j<i; j++)
    {
        if(adja[i][j]==1 && colour[j]==k)
            return 0;
    }
    return 1;
}
void graphcolor(int k)
{
    int i, j;
    for(i=1; i<=m; i++)
    {
        if(coltest(k, i))
        {
            colour[k]=i;
            if(k==n)
            {
                printf("\nNew Result:");
                for(j=1; j<=n; j++)
                    printf("\n Vertex %d: Color %d", j, colour[j]);
            }
            else
                graphcolor(k+1);
        }
    }
}
void main()
{
    int e, x, y, i;
    printf("\nEnter the number of vertices and the number of edges:");
    scanf("%d%d", &n, &e);
    printf("\nEnter the number of colors:");
    scanf("%d", &m);
    for(i=1; i<=e; i++)
    {
        printf("\nEnter the adjacent vertices:");
        scanf("%d%d", &x, &y);
        adja[x][y]=adja[y][x]=1;
    }
    graphcolor(1);
}
