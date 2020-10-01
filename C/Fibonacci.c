#include<stdio.h>
int main()
{
    int n, i, t1=0, t2=1, sum=0;
    printf("enter the number til which you want to see the fibonacci series:");
    scanf("%d", &n);
    printf("fibonacci series is til the %dth term:")
    for(i=2;i<=n;i++)
    {
     	sum= (t1+t2);
     	t1=t2;
     	t2=sum;
        printf("%d, ",n,sum);}
    return 0;
}
