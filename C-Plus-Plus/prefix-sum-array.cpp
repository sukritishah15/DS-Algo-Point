#include <bits/stdc++.h>
using namespace std;

int main() {
    /*
    Input specification: 
    - Integer n, m, q, the range of numbers, number of operations to make, and the number of queries respectively
    - M lines of L, R, x where [L, R] is the range that should be incremented by x
    - Q lines of L, R, the range sum from [L, R]
    constraints: 1<=L, R, <=n
    Sample Input:
    5 2 3
    2 4 5
    1 5 -2
    1 2
    2 4
    1 5
    Sample Output: 
    1 9 5
    Time complexity: O(n)
    Space complexity: O(n)
    */
   int n, m, q, l, r, x; vector<int> psa;
   cin >> n >> m >> q; psa.resize(n+2);
   //Only adding/subtracting the endpoints allows for an O(n) update (rather than an O(n^2))
   for (int i=1;i<=m;i++) {
       cin >> l >> r >> x;
       psa[l]+=x; psa[r+1]-=x;
   }
   //first iteration is to convert to normal array
   for (int i=1;i<=n;i++) psa[i]+=psa[i-1];
   //second interation is to convert to psa
   for (int i=1;i<=n;i++) psa[i]+=psa[i-1];
   for (int i=1;i<=q;i++) {
       cin >> l >> r;
       cout << psa[r]-psa[l-1] << " ";
   } cout << endl;
} 