#include <stdio.h>

void heap_sort(int [], int );
void heapify(int [], int , int );
void swap(int *, int *);
void print_array(int [], int );
int main() {
    int i, n, arr[100];
    printf("\nHow many elements? ");
    scanf("%d", &n);
    printf("\nEnter elements: ");
    for (i=0; i<n; i++)
        scanf("%d", &arr[i]);
    printf("\nOriginal Array: ");
    print_array(arr, n);
    heap_sort(arr, n);
    printf("\nSorted Array: ");
    print_array(arr, n);
}

void heap_sort(int arr[], int n) {
    int i;
    for (i = n/2; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (i = n-1; i>0 ; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// swap elements a and b in the array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// print the array
void print_array(int arr[], int n) {
    int i;
    for (i=0; i<n; i++)
        printf("%d ", arr[i]);  
}

/*
    Time Complexity : O(nlogn)
    Space Complexity : O(1)
    Input : 
        How many elements: 5
        Enter elements: 5 4 3 2 1
    Output : 
        Original Array: 5 4 3 2 1
        Sorted Array: 1 2 3 4 5
*/