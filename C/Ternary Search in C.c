#include <stdio.h>

int ternarySearch(int array[], int start, int end, int key) {
   if(start <= end) {
      int midFirst = (start + (end - start) /3);
      int midSecond = (midFirst + (end - start) /3);
      if(array[midFirst] == key)
         return midFirst;
      if(array[midSecond] == key)
         return midSecond;
      if(key < array[midFirst])
         return ternarySearch(array, start, midFirst-1, key);
      if(key > array[midSecond])
         return ternarySearch(array, midSecond+1, end, key);
      return ternarySearch(array, midFirst+1, midSecond-1, key);
   }
   return -1;
}

int main() {
   int n, searchKey, loc;
   printf("Enter number of items: ");
   scanf("%d", &n);
   int arr[n];
   printf("Enter items: ");

   for(int i = 0; i< n; i++) {
      scanf("%d", &arr[i]);
   }

   printf("Enter search key to search in the list: ");
   scanf("%d", &searchKey);
   if((loc = ternarySearch(arr, 0, n, searchKey)) >= 0)
      printf("Item found at location: %d", loc);
   else
      printf("Item is not found in the list.");
}

/*
Input:
Enter number of items: 8
Enter items:
12 25 48 52 67 79 88 93
Enter search key to search in the list: 52
Output:
Item found at location: 3
*/

/*
Time Complexity: O(log_3 n)
Space Complexity: O(1)
*/
