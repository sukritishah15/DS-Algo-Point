#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int CountPalindrome(char str[], int n)
{
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    bool P[n][n];
    memset(P, false, sizeof(P));

    for (int i = 0; i < n; i++)
        P[i][i] = true;

    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            P[i][i + 1] = true;
            dp[i][i + 1] = 1;
        }
    }

    for (int gap = 2; gap < n; gap++)
    {
        // Pick starting point for current gap
        for (int i = 0; i < n - gap; i++)
        {
            // Set ending point
            int j = gap + i;

            // If current string is palindrome
            if (str[i] == str[j] && P[i + 1][j - 1])
                P[i][j] = true;

            // Add current palindrome substring ( + 1)
            // and rest palindrome substring (dp[i][j-1] + dp[i+1][j])
            // remove common palindrome substrings (- dp[i+1][j-1])
            if (P[i][j] == true)
                dp[i][j] = dp[i][j - 1] + dp[i + 1][j] + 1 - dp[i + 1][j - 1];
            else
                dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
        }
    }

    // return total palindromic substrings
    return dp[0][n - 1];
}
int main()
{
    int n;
    scanf("%d", &n);
    char str[n];
    scanf("%s", str);
    printf("%d", CountPalindrome(str, n));
}

/*
Time Complexity - O(n^2)
Space Complexity - O(n^2)

Input : 5
        abaab
Output : 3
*/