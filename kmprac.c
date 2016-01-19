#include<stdio.h>
#include<string.h>
char P[100], T[100];
int pi[100];
int n, m;
void prefixfunction()
{
    int q, k;
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
void kmpmatcher()
{
    int q, i;
    prefixfunction();
    q=pi[1];
    for(i=1; i<=n; i++)
    {
        while(q>0 && P[q+1]!=T[i])
            q=pi[q];
        if(P[q+1]==T[i])
            q++;
        if(q==m)
            {
                printf("\nThe pattern occurs with shift %d.", (i-m));
                q=pi[q];
            }
    }
}
void main()
{
    char str[100];
    int i, j;
    printf("\nEnter the text:");
    gets(str);
    for(i=1; str[i-1]!='\0'; i++)
        T[i]=str[i-1];
    n=strlen(str);
    printf(str);
    printf("\nEnter the pattern:");
    gets(str);
    for(i=1; str[i-1]!='\0'; i++)
        P[i]=str[i-1];
    m=strlen(str);
    printf(str);
    kmpmatcher();
}
