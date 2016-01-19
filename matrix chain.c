#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
    int p[10], mat[10][10], n, i, j, l, k, min, po;
    printf("\nEnter the number of matrices:");
    scanf("%d", &n);
    for(i=0; i<=n; i++)
    {
        printf("\nEnter p[%d]:", i);
        scanf("%d", &p[i]);
    }
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=n; j++)
        mat[i][j]=0;
    }
    for(l=1; l<=n-1; l++)
    {
        for(i=1; i<=n-l; i++)
        {
            j=i+l;
            k=i;
            min=mat[i][k]+mat[k+1][j]+p[i-1]*p[k]*p[j];
            for(++k; k<j; k++)
            {
                po=mat[i][k]+mat[k+1][j]+p[i-1]*p[k]*p[j];
                if(po<min)
                    min=po;
            }
            mat[i][j]=min;
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(mat[i][j]==0 && i!=j)
                continue;
            else
                printf("\t%d", mat[i][j]);
        }
        printf("\n");
    }
    printf("\nThe minimum number of computations is %d", mat[1][n]);
}
