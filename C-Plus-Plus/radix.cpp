#include <bits/stdc++.h>
using namespace std;

/*
Input Format: size of the array and the contents of the array
Output Format: the sorted array
ALgorithm: Radix Sort
Time Complexity: O((n+b) * logb(k)), where n is the number of elements, b is the base of the number, 
				 k is the greatest element of the array
Space Complexity: O(n)

Sample Input and Output

**Sample Input 1:**

Enter the number of elements of the array: 8

Enter the array elements : 2632 1515 1495 9657 1452 2053 1025 3050

The sorted array is : 1025 1452 1495 1515 2053 2632 3050 9657


**Sample Input 2:**

Enter the number of elements of the array: 10

Enter the array elements : 214 632 789 147 896 325 741 89 10 30

The sorted array is : 10 30 89 147 214 325 632 741 789 896
*/

// utility function that sorts the array elements based on a particular digit of the array element
void countSort(vector<int> &a, int exp)
{
  int n = (int)a.size();
  vector<int> tmp(n); // tmp array
  int i, count[10] = {0};

  // Store count of occurrences in count vector
  for (i = 0; i < n; i++)
    count[(a[i] / exp) % 10]++;

  // Change count[i] so that count[i] now contains actual
  // position of this digit in tmp vector
  for (i = 1; i < 10; i++)
    count[i] += count[i - 1];

  // Build the tmp array
  for (i = n - 1; i >= 0; i--)
  {
    tmp[count[(a[i] / exp) % 10] - 1] = a[i];
    count[(a[i] / exp) % 10]--;
  }

  // Copy the tmp vector to a, so that vector a now
  // contains sorted numbers according to current digit
  a = tmp;
}

// Radix Sort implementation
void radixsort(vector<int> &a)
{
  int m = *max_element(a.begin(), a.end());

  /*
	Do counting sort for every digit. Note that instead
	of passing digit number, exp is passed. exp is 10^i
	where i is current digit number
	*/
  for (int exp = 1; m / exp > 0; exp *= 10)
  {
    countSort(a, exp);
  }
}

// utility function to print the array
void print(vector<int> &a)
{
  for (int u : a)
  {
    cout << u << " ";
  }
  cout << '\n';
}

// Driver Code
int main()
{
  int n;
  vector<int> a;
  cout << "\nEnter the number of elements of the array: ";
  cin >> n;
  a.resize(n);
  cout << "\nEnter the array elements : \n";
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  radixsort(a);
  cout << "\nThe sorted array is : ";
  print(a);
  return 0;
}
