#include <iostream>
#define n 3
using namespace std;
int getLongestPathLengthUtil(int i, int j, int matrix[n][n], int table[n][n]) {
   if (i < 0 || i >= n || j < 0 || j >= n)
   return 0;
   if (table[i][j] != -1)
      return table[i][j];
   int x = INT_MIN, y = INT_MIN, z = INT_MIN, w = INT_MIN;
   if (j < n - 1 && ((matrix[i][j] + 1) == matrix[i][j + 1]))
      x = 1 + getLongestPathLengthUtil(i, j + 1, matrix, table);
   if (j > 0 && (matrix[i][j] + 1 == matrix[i][j - 1]))
      y = 1 + getLongestPathLengthUtil(i, j - 1, matrix, table);
   if (i > 0 && (matrix[i][j] + 1 == matrix[i - 1][j]))
      z = 1 + getLongestPathLengthUtil(i - 1, j, matrix, table);
   if (i < n - 1 && (matrix[i][j] + 1 == matrix[i + 1][j]))
      w = 1 + getLongestPathLengthUtil(i + 1, j, matrix, table);
      return table[i][j] = max(x, max(y, max(z, max(w, 1))));
}
int getLongestPathLength(int matrix[n][n]) {
   int result = 1;
   int table[n][n];
   for(int i = 0; i < n; i++)
   for(int j = 0; j < n; j++)
   table[i][j] = -1;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if (table[i][j] == -1)
         getLongestPathLengthUtil(i, j, matrix, table);
         result = max(result, table[i][j]);
      }
   }
   return result;
}
int main() {
   int mat[n][n] ;
   for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
   {
       cin>>mat[i][j];
   }
}
   cout << "Length of the longest path is "<< getLongestPathLength(mat);
}

/*
Sample input:
[[1, 2, 3],
[6, 13, 4],
[6, 7, 9]]

Output:
Length of the longest path is 4.
*/

/*
Time complexity is O(n^2).
Space complexity is O(n).
*/

