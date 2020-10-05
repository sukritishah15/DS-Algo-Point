#include <stdio.h>

//Given the value of n,find the sum of the Fibonacci series
int main()
{
    int num1=0,num2=1,num3;
    int n;
    int sum=1;
    printf("Enter the value of n\n");
    scanf("%d",&n);

    for(int i=2;i<n;i++)
    {
        num3=num1+num2;
        num1=num2;
        num2=num3;
        sum=sum+num3;
    }
    printf("Sum=%d",sum);
    return 0;
}

/*SAMPLE INPUT:
6
SAMPLE OUTPUT:
Sum=12

Time Complexity: O(n)
Space Complexity: O(1) */
