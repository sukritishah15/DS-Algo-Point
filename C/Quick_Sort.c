#include<stdio.h> 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];   
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    {
        if (arr[j] <= pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]);
} 
  
int main() 
{ 
    int n;
    printf("Enter the number of elements you want to enter: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
	scanf("%d",&arr[i]);
    quickSort(arr, 0, n-1); 
    printf("Sorted array: "); 
    printArray(arr, n); 
    return 0; 
} 
    /*
    Problem name :- Quick Sort
    
    Input:
    
    Enter the number of elements you want to enter: 5
    Enter the elements: 5
    9
    1
    6
    7
    
    Output:
    
    Sorted array: 1 5 6 7 9
    
    Time Complexity:- O(n)
    Space Complexity:- O(log n)
    */
