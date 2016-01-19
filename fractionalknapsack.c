#include<stdio.h>
#include<conio.h>
typedef struct object
{
    int profit;
    int weight;
    float ppw;
    int index;
}obj;
void main()
{
   obj arr[100], solution[100], temp;
   int n, i, j, m;
   float netprofit;
   printf("\nEnter the number of objects:");
   scanf("%d", &n);
   printf("\nEnter the capacity of the knapsack:");
   scanf("%d", &m);
   for(i=1; i<=n; i++)
   {
       printf("\nEnter the profit of item %d:", i);
       scanf("%d", &arr[i].profit);
       printf("\nEnter the weight of item %d:", i);
       scanf("%d", &arr[i].weight);
       arr[i].ppw=(float)arr[i].profit/arr[i].weight;
       arr[i].index=i;
   }
   for(i=1; i<=n-1; i++)
   {
       for(j=1; j<=n-i; j++)
       {
           if(arr[j].ppw<arr[j+1].ppw)
           {
               temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
           }
       }
   }
   i=j=1;
   netprofit=0;
   while(arr[i].weight<=m)
   {
        solution[j]=arr[i];
        netprofit+=arr[i].profit;
        m-=arr[i].weight;
        j++;
        i++;

   }
   if(m!=0)
   {
       solution[j]=arr[i];
       netprofit+=m*arr[i].ppw;
   }
   while(j--)
   {
       printf("\n%d", arr[j].index);
   }
   printf("\nNet profit=%f", netprofit);

}
