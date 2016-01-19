#include<stdio.h>
void main()
{
    int adja[50][50], n, i, j, min, flag, visited[50], minr, solution[50], t;
    printf("\nEnter the number of vertices:");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf("\nEnter the cost of the path between vertices %d and %d:", i, j);
            scanf("%d", &adja[i][j]);
        }
    }
    t=1;
    visited[1]=1;
    solution[t++]=1;
    while(1)
    {
        for(i=1, flag=0; i<=n; i++)
        {
            if(visited[i]==1)
            {
                for(j=1; j<=n; j++)
                {
                    if(flag==0 && visited[j]==0)
                    {
                        flag=1;
                        min=adja[i][j];
                        minr=j;
                    }
                    else if(adja[i][j]<min && visited[j]==0)
                    {
                        min=adja[i][j];
                        minr=j;
                    }
                }
            }
        }
        visited[minr]=1;
        solution[t++]=minr;
        for(i=1; i<=n; i++)
        {
            if(visited[i]==0)
                break;
        }
        if(i>n)
            break;
    }
    printf("\nThe solution is:");
    for(i=1; i<=n; i++)
        printf("%d    ", solution[i]);
}
