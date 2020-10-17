#include<stdio.h>


int main()
{
  int x=2, y=1;
  //code to swap x and y
  x=x+y;
  y=x-y;
  x=x-y;

  printf("After swapping: x = %d, y = %d\n", x, y );

  return 0;
}

/*sample output:
After swapping: x = 1, y = 2
*/
