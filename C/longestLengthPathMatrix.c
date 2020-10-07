#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int lin;
  int col;
} pos;

typedef struct {
  pos * v;
  int start;
  int end;
  int max;
} line;

line * newLine (int size){
  line * l = malloc(sizeof(line));
  l->v = malloc(size * sizeof(pos));
  l->max = size;
  l->start = l->end = 0;
  return l;
}

void insertLine(pos p, line * l){
  l->v[l->end] = p;
  l->end = (l->end + 1) % l->max;
}

pos removeLine(line * l){
  pos first;
  if (!(l->start == l->end)){
    first = l->v[l->start];
    l->start = (l->start + 1) % l->max;
    return first;
  }
}

int longestLength(int ** matrix, int l, int c){
  int i, j, d, temp, longest = 0, keepGoing = 1;
  line * leng = newLine(l * c);
  pos act, next;
  int px[4] = {1, 0, -1, 0};
  int py[4] = {0, 1, 0, -1};
  for (i = 0; i < l; i++){
    for (j = 0; j < c; j++){
      act.lin = i;
      act.col = j;
      temp = matrix[i][j];
      insertLine(act, leng);
      keepGoing = 1;
      while(keepGoing){
        if (leng->start == leng->end){
          keepGoing = 0;
        }
        else{
          act = removeLine(leng);
          for (d = 0; d < 4; d++){
            next.lin = act.lin + px[d];
            next.col = act.col + py[d];
            if (next.lin >= 0 && next.lin < l && next.col >= 0 && next.col < c 
                && matrix[next.lin][next.col] == matrix[act.lin][act.col] + 1){
              if (matrix[next.lin][next.col] - temp > longest)
                longest = matrix[next.lin][next.col] - temp;
              insertLine(next, leng);
            }
          }
        }
      }
      leng->start = 0;
      leng->end = 0;
    }
  }
  return (longest + 1);
}

int main(){
  int l, c, i, j, ind;
  int ** matrix;
  printf("Please enter the matrix size, lines and columns: ");
  scanf("%d%d", &l, &c);
  matrix = malloc(l * sizeof(int *));
  for (ind = 0; ind < l; ind++){
    matrix[ind] = malloc(c * sizeof(int));
  }
  printf("Enter the matrix:\n");
  for (i = 0; i < l; i++){
    for (j = 0; j < c; j++){
      scanf("%d", &matrix[i][j]);
    }
  }
  printf("%d\n", longestLength(matrix, l, c));
  return 0;
}

/*
Example:
Input: 3 3
1 0 9
2 3 8
4 6 7
Output: 4

Time Complexity: O((l*c)^2)
Space Complexity: O(l*c)
*/