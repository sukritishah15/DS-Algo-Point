//Using GCD, find LCM of two number.

#include <iostream>
#include <numeric> 
using namespace std;

// Gcd recursive Function
long long gcd(long long int x, long long int y)
{
  if (y == 0)
    return x;
    //Rcursive function
  return gcd(y, x % y);
}

// Lcm Function
long long lcm(int a, int b)
{
	//return Lcm of two number
    return (a / gcd(a, b)) * b;
}

//main function
int main()
{
	//Input 2 numbers for Lcm
    int n1, n2;
    cout << "Enter two numbers: ";
    cin >> n1 >> n2;
    //Print output
    cout<<"\tOUTPUT\n";
    //calling Lcm Funtion
    cout <<"LCM of " << n1 << " and "
         << n2 << "--> " << lcm(n1, n2); 
 
    return 0;
}
/*Sample Input Output

Sample 1.
Enter two numbers : 761457 614573

	OUTPUT
LCM of 761457 and 614573 --> 467970912861

Sample 2.
Enter two numbers : 6 8

	OUTPUT
LCM of 6 and 8 --> 24

Time Complexity :O(logn)
Space Complexity:O(1)

*/

