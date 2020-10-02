#include <iostream>

int compute_gcd(int a, int b)
{
  if (b)
  {
    a = a % b;
    return compute_gcd(b, a);
  }
  else
  {
    return a;
  }
}

int main()
{
  int a, b;
  std::cin >> a >> b;
  std::cout << compute_gcd(a, b) << std::endl;
  return 0;
}
/*
Input:
200 900
Output:
100
Time complexity: O(log (n)) 
Space Complexity: O(log (n))
*/
