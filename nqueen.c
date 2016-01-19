#include<stdio.h>
#include<conio.h>
int x[100], n;
int place(i, k)
{
    int j;
    for(j=1; j<k ; j++)
    {
        if(i==x[j] || (abs(k-j)==abs(i-x[j])))
            return 0;
    }
    return 1;
}
void NQUEEN(k)
{
    int i, j;
    for(i=1; i<=n; i++)
    {
        if(place(i, k))
        {
            x[k]=i;
            if(k==n)
            {
                printf("\n");
                for(j=1; j<=n; j++)
                    printf("%d  ", x[j]);
            }
            else
                NQUEEN(k+1);
        }
    }
}
void main()
{
    printf("\nEnter the number of queens:");
    scanf("%d", &n);
    NQUEEN(1);
}
