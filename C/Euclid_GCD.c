// Program to find GCD of two numbers using Euclidean GCD algorithm
// This program returns GCD in O(log(N)) time. 

#include <stdio.h>

int euclids_gcd(int a,int b) // recursive function 
{
    if(b == 0)
    {
        return a;
    }
    return euclids_gcd(b, a%b); 
}

int print_gcd(int a,int b)
{
    int ans = euclids_gcd(a,b);
    printf("GCD of above numbers is %d",ans);
}
int main()
{
    int a,b;
    printf("Enter 2 number's for which GCD is required \n");
    scanf("%d %d",&a,&b);
    print_gcd(a,b); 
 
    return 0;
}

/*

Enter 2 number's for which GCD is required                                                                                      
4 8                                                                                                                             
GCD of above numbers is 4       

*/
