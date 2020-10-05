//No of Permutations and Combinations
#include <stdio.h>
int factorial(int num) //Finding Factorial Using Recursion
{
    if (num == 1 || num == 0) //Base Case (0!=1!=1)
    {
        return 1;
    }
    else
    {
        return (num * factorial(num - 1));
    }
}
int permutation(int n, int r) //P(n,r)=n!/(n-r)!
{
    return (factorial(n) / factorial(n - r));
}
int combination(int n, int r) //C(n,r)=n!/((n-r)!*(r!))
{
    return (factorial(n) / (factorial(r) * factorial(n - r)));
}

int main()
{
    int n, r, per, com;
    scanf("%d %d",&n, &r);
    per = permutation(n, r);
    com = combination(n, r);
    printf("%d\n%d", per, com);
}

/*
Sample Input 
Enter values of (n,r) for P(n,r) and C(n,r)
9 4
Sample Output
3024            (Permutation)
126             (Combination)
______________________________________________
Time Complexity:O(n)
Space Complexity:O(n)
*/