//Selection sort implementation in C
#include <stdio.h>

//Function for swapping two elements in an array
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Function to perform selection sort
void selectionSort(int n,int arr[]){
    int min;
    for(int j=0;j<n-1;j++){
        min = arr[j];
        for(int k=j+1;k<n;k++){
            if(arr[k]<min){
                min = arr[k];
                //printf("swapping %d and %d\n",arr[j],arr[k]);
                swap(&arr[j],&arr[k]);
            }
        }
    }
}


int main(void) {
	int n;
	printf("Enter array size:\n");
	scanf("%d",&n);
	
	int arr[n];
	
	for(int i=0;i<n;i++){
	    scanf("%d",&arr[i]);
	}
	
	printf("Array before sorting:\n");
	
	//Displaying array before sorting
	for(int i=0;i<n;i++){
	    printf("%d",arr[i]);
	    printf(" ");
	}
	printf("\n");
	
	selectionSort(n,arr);
	
	printf("Array after sorting:\n");
	
	//Displaying array after sorting
	for(int i=0;i<n;i++){
	    printf("%d",arr[i]);
	    printf(" ");
	}
	printf("\n");
	
	return 0;
}

/*
Selection sort is a simple sorting algorithm. During it's execution, it effectively creates two parts of the
array.The left part is sorted and right is unsorted.During the first iteration it places the smallest element 
at the start of the array.In further iterations the next smallest elements are found and are kept adding to the 
left ie. sorted part.At the end we get a sorted array. 

Time Complexity : O(n2)
Space Complexity : O(1)

Sample I/O : 
Enter array size:10
Array before sorting:
1 8 4 2 3 9 20 4 5 0 
Array after sorting:
0 1 2 3 4 4 5 8 9 20 
*/
