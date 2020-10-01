#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

// A comparison function which is used by sort() in printLargest()
int myCompare(string X, string Y)
{
  // first append Y at the end of X
  string XY = X.append(Y);
  // then append X at the end of Y
  string YX = Y.append(X);
  // Now see which of the two formed numbers is greater
  return XY.compare(YX) > 0 ? 1 : 0;
}
string largest_number(vector<string> arr)
{
  std::stringstream ret;
  sort(arr.begin(), arr.end(), myCompare);

  for (size_t i = 0; i < arr.size(); ++i)
  {
    ret << arr[i];
  }
  string result;
  ret >> result;

  return result;
}

int main()
{
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
/* 
Problem: construct biggest number from given set of numbers

Input:
2
21 2

Output:
221

Space Complexity: O(1)
Time complexity: O(log(a + b)) = O(log n)
*/