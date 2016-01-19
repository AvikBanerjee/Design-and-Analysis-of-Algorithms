#include<stdio.h>
#include<string.h>
void main()
{
    char P[100], T[100];
    int i, j, n, m, flag;
    printf("\nEnter the pattern:");
    gets(P);
    printf("\nEnter the text:");
    gets(T);
    n=strlen(T);
    m=strlen(P);
    for(i=0; i<=n-m; i++)
    {
        for(j=0, flag=0; j<m; j++)
        {
            if(P[j]!=T[i+j])
            {
                flag=1;
                break;
            }
        }
        if(!flag)
            printf("\nThe pattern occurs with shift %d.", i);
    }
}
