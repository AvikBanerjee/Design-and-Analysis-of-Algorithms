#include<stdio.h>
int p[100], n, arr[100][100], s[100][100] ;
void matrixchain()
{
    int i, j, l, k, min=0, temp, mink;
    for(i=1; i<=n; i++)
        arr[i][i]=0;
    for(l=1; l<=n-1; l++)
    {
        for(i=1; i<=n-l; i++)
        {
            j=i+l;
            for(k=i, min=0; k<j; k++)
            {
                temp=arr[i][k]+arr[k+1][j]+p[i-1]*p[k]*p[j];
                if(min==0)
                    {
                        min=temp;
                        mink=k;
                    }
                else if(temp<min)
                    {
                        min=temp;
                        mink=k;
                    }
            }
            arr[i][j]=min;
            s[i][j]=mink;

        }
    }
}
void optimal_parens(i, j)
{
    if(i==j)
        printf("A[%d]", i);
    else
    {
        printf("(");
        optimal_parens(i, s[i][j]);
        optimal_parens(s[i][j]+1, j);
        printf(")");
    }
}
void main()
{
    int i;
    printf("\nEnter the number of matrices:");
    scanf("%d", &n);
    for(i=0; i<=n; i++)
    {
        printf("\nEnter p[%d]:", i);
        scanf("%d", &p[i]);
    }
    matrixchain();
    printf("\nMinimum number of scalar multiplications:%d", arr[1][n]);
    printf("\nOptimal parenthesization:\n");
    optimal_parens(1, n);
}
