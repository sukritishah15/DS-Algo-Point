// C++ program to find minimum number of denominations
/*Given a value V, if we want to make change for V Rs, and we have infinite supply of each of the denominations in Indian currency, i.e., we have infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins and/or notes needed to make the change?
*/
#include <bits/stdc++.h> 
using namespace std; 
  
// All denominations of Indian Currency 
int deno[] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000 }; 
int n = sizeof(deno) / sizeof(deno[0]); 
  
// Driver program 
void findMin(int V) 
{ 
    // Initialize result 
    vector<int> ans; 
  
    // Traverse through all denomination 
    for (int i = n - 1; i >= 0; i--) { 
        // Find denominations 
        while (V >= deno[i]) { 
            V -= deno[i]; 
            ans.push_back(deno[i]); 
        } 
    } 
  
    // Print result 
    for (int i = 0; i < ans.size(); i++) 
        cout << ans[i] << "  "; 
} 
  
// Driver program 
int main() 
{ 
    int n = 93; 
    cout << "Following is minimal number of change for " << n << " is "; 
    findMin(n); 
    return 0; 
} 

/*

Complexity Analysis:

Time Complexity: O(V).
Auxiliary Space: O(1) as no additional space is used.


Sample output: 
Following is minimal number of change for 93 is 50  20  20  2  1

*/
