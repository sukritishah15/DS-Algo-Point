#include <stdio.h>

typedef struct {
  int x;
  int y;
} coord;


int manhattanDistance(coord a, coord b){
  int dist = 0;
  if (a.x > b.x)
    dist += a.x - b.x;
  else
    dist += b.x - a.x;
  
  if (a.y > b.y)
    dist += a.y - b.y;
  else
    dist += b.y - a.y;
  
  return dist; 
}

int main(){
  coord a, b;
  printf("Enter coordinates of a:\n");
  scanf("%d %d", &a.x, &a.y);
  printf("Enter coordinates of b:\n");
  scanf("%d %d", &b.x, &b.y);
  printf("%d\n", manhattanDistance(a, b));
  return 0;
}

/*
Example:
Input: 1 4 4 1
Output: 6

Time complexity: O(1)
Space complexiity: O(1)
*/