#include<stdio.h>
void optparenthesize(int s[][10], int i, int j)
{
    if(i==j)
        printf("A%d", i);
    else
    {
        printf("(");
        optparenthesize(s, i, s[i][j]);
        optparenthesize(s, s[i][j]+1, j);
        printf(")");
    }
}
void main()
{
    int p[10], m[10][10], i, j, n, l, min, s[10][10], pos, k;
    printf("\nEnter the number of matrices:");
    scanf("%d", &n);
    for(i=0; i<=n; i++)
    {
        printf("\nEnter p%d:", i);
        scanf("%d", &p[i]);
    }
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=n; j++)
            m[i][j]=0;
    }
    printf("\nSet to zero.\n");
    for(l=1; l<=n-1; l++)
    {
        for(i=1; i<=n-l; i++)
        {
            j=i+l;
            k=i;
            min=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
            s[i][j]=k;
            for(++k; k<j; k++)
            {
                pos=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(pos<min)
                {
                    min=pos;
                    s[i][j]=k;
                }
            }
            m[i][j]=min;
        }
    }
    printf("\nThe minimum number of scalar computations required is: %d", m[1][n]);
    optparenthesize(s, 1, n);
}
