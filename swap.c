#include<stdio.h>
/*void swap(int &x, int &y)
{
    x=x+y;
    x=x-y;
    y=x-y;
}*/
void main()
{
    int a=20, b=30, x;
    &x=&a;
    swap(a, b);
    printf("\n%d\n%d", a, b);
}
