#include<stdio.h>
#include<math.h>
int arr[100][100]={0}, n, solution[100], covered[100], t=0;
int check(int i, int j);
void main()
{
    int i, j, min, minr, minc, flag;
    printf("\nEnter the number of vertices:");
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        for(j=1; j<=n; j++)
        {
            printf("\nEnter the weight of the path between vertices %d and %d:", i, j);
            scanf("%d", &arr[i][j]);
        }

    }
    while(1)
    {
        for(i=1, flag=0; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(flag==0 && i!=j)
                {
                    min=arr[i][j];
                    minr=i;
                    minc=j;
                    flag=1;
                }
                else if(flag==1 && i!=j && arr[i][j]<min)
                {
                    min=arr[i][j];
                    minr=i;
                    minc=j;
                }
            }
        }
        arr[minr][minc]=10000;
        if(check(minr, minc))
        {
            if(covered[minr]==1)
                {
                    solution[t++]=minc;
                    covered[minc]=1;
                }
            else if(covered[minc]==1)
                {
                    solution[t++]=minr;
                    covered[minr]=1;
                }
            else
            {
                solution[t++]=minr;
                solution[t++]=minc;
            }
        }

    }
}

}
