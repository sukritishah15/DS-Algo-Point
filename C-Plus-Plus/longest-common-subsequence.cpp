#include <bits/stdc++.h>
using namespace std;

void lcs(int n, int m, string a, string b) {
    int dp[n+1][m+1]; memset(dp, 0, sizeof(dp));
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if(a[i-1]==b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << "The LCS is: " << dp[n][m] << "\n";
}
int main() {
    /*
    Input specification: 
    - Integer n, m
    - String a, b, the two strings with length n and m respectively
    Sample Input:
    3 5
    abc
    aabcc
    Sample Output: 
    The LCS is 3
    Time complexity: O(nm)
    Space complexity: O(nm)
    */
    int n, m; string a, b;
    cin >> n >> m;
    cin >> a >> b;
    lcs(n, m, a, b);
}