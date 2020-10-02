#include <bits/stdc++.h>
using namespace std;

/*
Input Format: number to factorise
Output Format: all the prime factors of the numbers
ALgorithm: Prime Factorisation in LogN 
Time Complexity: This algorithm uses O(N) precomputation. But if we have multiple queries to factorise
the number, we can factorise the numbers in logN per query
Space Complexity: O(N)

Sample Input and Output

**Sample Input 1:**

Enter the number to Factorise: 12368
Prime factors of  12368 are : 2 2 2 2 773


**Sample Input 2:**

Enter the number to Factorise: 98568
Prime factors of  98568 are : 2 2 2 3 3 37 37
*/

// maximum number limit it can factorise
const int maxN = 1e6 + 10;

// vector to store the smallest prime factors of the numbers
vector<int> smallestPrimeFactor;

// precomputes the smallest prime factors of all numbers from 1 to maxN-1
void precompute()
{
  smallestPrimeFactor.resize(maxN);
  smallestPrimeFactor[1] = 1;
  for (int i = 1; i < maxN; i++)
  {
    smallestPrimeFactor[i] = i;
  }
  for (int i = 2; i < maxN; i++)

    // marking smallest prime factor for every
    // number to be itself.
    smallestPrimeFactor[i] = i;

  // separately marking smallestPrimeFactor for every even
  // number as 2
  for (int i = 4; i < maxN; i += 2)
    smallestPrimeFactor[i] = 2;

  for (int i = 3; i * i < maxN; i++)
  {
    // checking if i is prime
    if (smallestPrimeFactor[i] == i)
    {
      // marking SPF for all numbers divisible by i
      for (int j = i * i; j < maxN; j += i)

        // marking smallestPrimeFactor[j] if it is not
        // previously marked
        if (smallestPrimeFactor[j] == j)
        {
          smallestPrimeFactor[j] = i;
        }
    }
  }
}

// A O(log N) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int target)
{
  vector<int> ret;
  while (target != 1)
  {
    ret.push_back(smallestPrimeFactor[target]);
    target = target / smallestPrimeFactor[target];
  }
  return ret;
}

// driver program for above function
int main()
{
  // precalculating Smallest Prime Factor of all numbers till maximum limit
  precompute();

  int number;
  cout << "\nEnter the number to Factorise: ";
  cin >> number;
  cout << "Prime factors of  " << number << " are : ";

  // calling getFactorization function
  vector<int> p = getFactorization(number);

  // printing the prime factors of the numbers
  for (int i = 0; i < (int)p.size(); i++)
  {
    cout << p[i] << " ";
  }
  cout << '\n';
  return 0;
}