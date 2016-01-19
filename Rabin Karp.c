#include<stdio.h>
#include<math.h>
#include<string.h>
char T[100], P[100], n, m;
void rabinkarp()
{
    long m, n, h, p, t, i;
    n=strlen(T);
    m=strlen(P);
    h=(pow(10, m-1))%13;
    p=0;
    t=0;
    for(i=0; i<m; i++)
    {
        p=(10*p+P[i])%13;
        t=(10*t+T[i])%13;
    }
    for(s=0; s<=n-m; s++)
    {
        if(p==t)
        {
            for(i=0, flag=0; i<m; i++)
            {

            }
        }
    }
}
