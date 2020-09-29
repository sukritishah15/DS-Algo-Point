// A very quick and dirty “implementation” of insertion sort in plain C however, due to the nature of C, this technically isn't a pure insertion sort algorithm as you cannot (easily at all) prepend an item to an array/list in C natively without lots of boilerplate. Other languages (thankfully) provide this functionality. Therefore this implementation instead iterates over the pre-sorted section of the list (before the list’s pointer) moving the smaller value further down the list where needed. In other languages, the value can be directly inserted at the correct index but in C you cannot without using the method specified above. -J
#include <stdio.h>
void dirtyPrintArray(int arr[], int len)
{
  printf("[");
    for (int i=0; i <= (len)-1; i++) {
        printf("%d, ",arr[i]);
    }
  printf("]\n");
}
int main()
{
  int list[] = {12, 11, 13, 5, 6, 24, 9}; // Example list
  int len = *(&list+1)-list;
  dirtyPrintArray(list,len);
  for (int i = 1; i != len; i++) {
    dirtyPrintArray(list,len);
    int temp = list[i];
    int j = i-1;
    for (j; ((temp < list[j]) && (j > -1)); j--) {
      list[j+1] = list[j];
    }
    list[j+1] = temp;
  }
  dirtyPrintArray(list,len);
  return(0);
}
