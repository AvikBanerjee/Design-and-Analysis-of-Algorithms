#include<stdio.h>
#include<string.h>
void main()
{
    char P[100], T[100];
    long m, n, d=10, h, i, j, p, t, q=13, flag;
    printf("\nEnter the pattern:");
    gets(P);
    printf("\nEnter the text:");
    gets(T);
    m=strlen(P);
    n=strlen(T);
    for(i=1, h=1; i<=m-1; i++)
    {
        h*=d;
    }
    h%=q;
    for(i=0, p=t=0; i<m; i++)
    {
        p=(d*p+(P[i]-'0'))%q;
        t=(d*t+(T[i]-'0'))%q;
    }
    for(i=0; i<=n-m; i++)
    {
        if(p==t)
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
                printf("\nPattern occurs with shift %ld.", i);
        }
        t=(d*(t-h*(T[i]-'0'))+(T[i+m]-'0'))%q;
        if(t<0)
            t+=q;
    }
}
