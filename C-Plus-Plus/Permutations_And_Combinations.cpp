//No of Permutations and Combinations
#include <iostream>
using namespace std;
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
    cin >> n >> r;
    per = permutation(n, r);
    com = combination(n, r);
    cout << per << "\n"
         << com;
}

/*
Sample Input 
Enter values of (n,r) for P(n,r) and C(n,r)
 7 4
Sample Output
840            (Permutation)
35             (Combination)
______________________________________________
Time Complexity:O(n)
Space Complexity:O(n)
*/