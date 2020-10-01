/*
Input:
a1 = 1
a2 = 2
n=4

Output:
8

Explanation:
The G.P. for this example would be - 1, 2, 4, 8, 16, ...

*/

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
    double a1, a2, n;
    cout << "Enter first term: ";
    cin >> a1;
    cout << "Enter second term: ";
    cin >> a2;
    cout << "Enter n: ";
    cin >> n;
    if (a1 == 0)
    {
        cout << " Division By Zero " << endl;
        exit(0);
    }
    double r = a2 / a1;
    double tn = a1 * pow(r, n - 1);
    cout << tn;

    return 0;
}

/*
Time and Space Complexity - O(1)
*/
