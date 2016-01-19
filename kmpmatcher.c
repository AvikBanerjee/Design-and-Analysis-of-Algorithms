#include<stdio.h>
#include<string.h>
int pi[100], m, n;
char P[100], T[100], str[100];
void compute_prefix_function()
{
    int k, q;
    pi[1]=0;
    k=0;
    for(q=2; q<=m; q++)
    {
        while(k>0 && P[k+1]!=P[q])
            k=pi[k];
        if(P[k+1]==P[q])
            k++;
        pi[q]=k;
    }
}
void KMP_matcher()
{
    int q, i;
    q=0;
    compute_prefix_function();
    for(i=1; i<=n; i++)
    {
        while(q>0 && P[q+1]!=T[i])
            q=pi[q];
        if(P[q+1]==T[i])
            q++;
        if(q==m)
        {
            printf("\nPattern occurs with shift %d.", i-m);
            q=pi[q];
        }

    }
}
void main()
{
    int i;
    printf("\nEnter the pattern:");
    gets(str);
    m=strlen(str);
    for(i=1; str[i-1]!='\0'; i++)
        P[i]=str[i-1];
    printf("\nEnter the text:");
    gets(str);
    n=strlen(str);
    for(i=1; str[i-1]!='\0'; i++)
        T[i]=str[i-1];
    KMP_matcher();
}
