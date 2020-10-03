/*0/1 Knapsack Problem: To find the maximum total value of items such that the total weight is within maximum capacity, 
also fractional weights are not allowed*/

#include<stdio.h>
#include<stdlib.h>

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int main(void)
{
    int n,weight,*value,**v,i,j,*w;
    printf("Enter n: ");
    scanf("%d",&n);
    w=(int*)malloc(n*sizeof(int));
    value=(int*)malloc(n*sizeof(int));
    printf("Enter weight and value of each of n items:\n");
    for(i=0;i<n;i++)
        scanf("%d%d",&w[i],&value[i]);
    printf("Enter maximum capacity of Knapsack: ");
    scanf("%d",&weight);
    v=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        v[i]=(int*)malloc((weight+1)*sizeof(int));
        for(j=0;j<=weight;j++)
        {
            if(j==0)
                v[i][j]=0;
            if(i==0)
            {
                if(j<w[i])
                    v[i][j]=0;
                else
                    v[i][j]=value[i];
            }
            else if(j>=w[i])
            {
                v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+value[i]);
            }
            else
                v[i][j]=v[i-1][j];
        }
    }
    printf("The total weight that can fit in the knapsack so as to obtain maximum value is: %d",v[n-1][weight]);
    return 0;
}

/*
Variable Description:
n-Number of items; weight-maximum capacity of knapsack; 
w[]-array of corresponding weights of items; value[]-array of corresponding values of items
v[][]-array for implementation of Dynamic Programming

max{}-function to return greater value number among the given two numbers

Time Complexity: O(n*weight)
Space Complexity: O(n*weight)

Sample i/o:

1) Enter n: 6
   Enter weight and value of each of n items:
   1 60
   2 30
   4 70
   3 50
   5 60 
   Enter maximum capacity of Knapsack: 5
   The total weight that can fit in the knapsack so as to obtain maximum value is: 130

2) Enter n: 8
   Enter weight and value of each of n items:
   3 60
   3 50
   8 22
   7 88
   2 33
   1 30
   4 25
   5 27
   Enter maximum capacity of Knapsack: 5
   The total weight that can fit in the knapsack so as to obtain maximum value is: 80

*/