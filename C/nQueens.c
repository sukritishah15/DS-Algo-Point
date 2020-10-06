#include <stdio.h>
#include <stdlib.h>

int ** newMatrix(int n){ // Create a matrix nxn with 0s
  int **mat;
  int ind, i, j;
  mat = malloc(n * sizeof(int *));
  for(ind = 0; ind < n; ind++){
    mat[ind] = malloc(n * sizeof(int));
  }
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      mat[i][j] = 0;
    }
  }
  return mat;
}

int freeSpace(int **mat, int line, int col, int n){ // Verify if the place have no queen able to attack it
  int i, j;
  for (i = 0; i < line; i++){
    if (mat[i][col] == 1)
      return 0;
  }
  for (i = 0; i < line; i++){
    j = (col - line) + i;
    if (j >= 0 && mat[i][j] == 1)
      return 0;
    j = (col + line) - i;
    if (j < n && mat[i][j] == 1)
      return 0;
  }
  return 1;
}

int nQueens(int n){
  int i, j, col, line, check;
  int *queens = malloc(n * sizeof(int));
  int **table = newMatrix(n);
  for (i = 0; i < n; i++){
    queens[i] = -1;
  }
  col = 0;
  line = 0;
  while (line < n){
    check = 0;
    while(!check && col < n){
      if(freeSpace(table, line, col, n))
        check = 1;
      else
        col++;
    }
    if (check){
      table[line][col] = 1;
      queens[line] = col;
      line++;
      col = 0;
    }
    else{
      if(line == 0)
        return 0;
      line--;
      col = queens[line];
      table[line][col] = 0;
      col++;
    }
  }
  return 1;
}
/*
int main() {
  int n;
  printf("Type n: ");
  scanf("%d", &n);
  if (nQueens(n))
    printf("It's possible.\n");
  else
    printf("It's impossible.\n");
  return 0;
}
*/

/*
Example1:
Input: 3
Output: 0
Example2:
Input: 8
Output: 1

Time Complexity: O(n^3)
Space Complexity: O(n^2)
*/