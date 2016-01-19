#include<stdio.h>
int adja[100][100];
void main()
{
    int n, covered[100]={0}, flag, min, solution[100], t=0, minj, i, j;
    printf("\nEnter the number of vertices:");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf("\nEnter the weight of edge [%d, %d]:", i, j);
            scanf("%d", &adja[i][j]);
        }
    }
    covered[1]=1;
    solution[t++]=1;
    while(1)
    {
        for(i=1, flag=0; i<=n; i++)
        {
            if(covered[i]==1)
            {
                for(j=1;j<=n; j++)
                {
                    if(flag==0 && covered[j]==0)
                    {
                        min=adja[i][j];
                        minj=j;
                        flag=1;
                    }
                    else if(flag==1 && covered[j]==0)
                    {
                        if(adja[i][j]<min)
                            {
                                min=adja[i][j];
                                minj=j;
                            }
                    }
                }
            }
        }
        covered[minj]=1;
        solution[t++]=minj;
        for(i=1, flag=0; i<=n; i++)
        {
            if(covered[i]==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
           break;
    }
    for(i=0;i<n; i++)
    printf("%d\t", solution[i]);
}
