#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
    else
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
}
int main()
{
    int i,val[20],wt[20],n;
    int W = 30;
    printf("Enter the query no. = ");
    scanf("%d",&n);
    printf("item\tweight\tvalue\n");
    for(i=0;i<n;i++)
    {
        printf("%d",i+1);
        scanf("%5d%5d",&wt[i],&val[i]);
    }
    printf("the optimal solution is = ");
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}
