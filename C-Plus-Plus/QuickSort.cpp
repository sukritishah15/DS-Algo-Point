// Quick sort in C++

#include <iostream>
using namespace std;

// Function to swap position of elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// Function to print eklements of an array
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

// Function to partition the array on the basis of pivot element
int partition(int array[], int low, int high) {
  // Select the pivot element
  int pivot = array[high];
  int i = (low - 1);

  // Put the elements smaller than pivot on the left 
  // and greater than pivot on the right of pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  printArray(array, 7);
  cout << "........\n";
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    // Select pivot position and put all the elements smaller 
    // than pivot on left and greater than pivot on right
    int pi = partition(array, low, high);

    // Sort the elements on the left of pivot
    quickSort(array, low, pi - 1);

    // Sort the elements on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

// Driver code
int main() 
{
  int n;
  int data[n];
  cin>>n;
  cout<<"Enter data: ";
  for(int i=0;i<n;i++)
  {
  	cin>>data[i];
  }
  quickSort(data, 0, n - 1);
  cout << "Sorted array in ascending order: \n";
  printArray(data, n);
  return 0;
}

/*
Sample I/O:

Enter data: 1 0 6 8 7 9 2 
........
1 0 2 8 7 9 6 
........
0 1 2 8 7 9 6 
........
0 1 2 6 7 9 8 
........
Sorted array in ascending order: 
0 1 2 6 7 8 9

-------------------------------------------------------------

Quicksort Complexities:

Time Complexities:
Worst Case Complexity [Big-O]: O(n^2)
Best Case Complexity [Big-omega]: O(n*log n)
Average Case Complexity [Big-theta]: O(n*log n)

Space Complexity: O(log n)
*/
