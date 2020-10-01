/*
    Input : size of array and the array 
    Output: Sorted Array
    Algorithm: Mergesort
    Time Complexity: O(n*log n)
    Space Complexity: O(n)
    
    Sample Input and Output:
    Enter the size of the array :5
    Enter the array elements :
     5 4 1 2 3
    Sorted Array :  1 2 3 4 5
    
*/



#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m;    
    int L[n1], R[n2];   // Taking temp arrays  left and right 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j];   
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)  
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
      while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
      while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  void mergeSort(int arr[], int l, int r) // Recursive Merge Sort
{ 
    if (l < r) 
    { 
        
        int m = l+(r-l)/2;  
       
        mergeSort(arr, l, m); // First Half
        mergeSort(arr, m+1, r);   // Last Half
        merge(arr, l, m, r); // Marge
    } 
}
int main(){
    int *arr,n,i;

    printf("Enter the size of the array :");
    scanf("%d",&n);
    printf("Enter the array elements :\n ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    printf("Sorted Array :\t");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }


}
