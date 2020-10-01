// C++ program for implementation of Heap Sort
#include <bits/stdc++.h> 
using namespace std; 

// Heapify utility
void heapify(int arr[], int n, int i) 
{ 
	int largest = i; // Initialize largest as the root 
	int l = 2*i + 1; // left child = 2*i + 1 
	int r = 2*i + 2; // right child = 2*i + 2 

	// left child>root 
	if (l < n && arr[l] > arr[largest]) 
		largest = l; 

	// right child>root
	if (r < n && arr[r] > arr[largest]) 
		largest = r; 

	// If largest is not the root
	if (largest != i) 
	{ 
		swap(arr[i], arr[largest]); 
		heapify(arr, n, largest); 
	} 
} 

// Function to implement heap sort
void heapSort(int arr[], int n) 
{ 
	// Building the heap 
	for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i); 
	for (int i=n-1; i>0; i--) 
	{ 
         
		swap(arr[0], arr[i]); // Move root to end

	
		heapify(arr, i, 0); 
	} 
} 

int main() 
{ 
    cout<<"Enter number of elements=";
    int n;cin>>n;
    cout<<"Enter the "<<n<<" elements : \n";
	int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    heapSort(a, n); 

	cout << "Sorted array by heap sort : \n"; 
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
} 

/*
Time Complexity : O(nlogn)
Space Complexity : O(1)
User is required to enter the size of array and then elements of array
in a space seperated manner. 
Input : 
6
6 7 1 9 2 8
Output : 
Sorted array by heap sort : 
1 2 6 7 8 9 
*/