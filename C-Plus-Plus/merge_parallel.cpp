/* C++ program for Merge Sort in linux based systems
compile using : g++ -pthread merge_parallel.cpp
run using : ./a.out $(cat ./input.txt)>file.txt

a.out is compiled code 

input is input.txt file located in same direcotry (sample content given below)
15 
13 215 35 846 38 318 38 84 98 4981 68 84 64 3846 846

file.txt is where output is stored (sample output given below)
Given array is 
13 215 35 846 38 318 38 84 98 4981 68 84 64 3846 846 

Sorted array is 
13 35 38 38 64 68 84 84 98 215 318 846 846 3846 4981 
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int arr[100], arr2[100];
// structure is defined because pthread takes only 1 argument
struct data {
  int start;
  int num;
};

/* Function to print an array */
void printArray(int A[], int size) {
  int i;
  for (i = 0; i < size; i++) printf("%d ", A[i]);
  printf("\n");
}
void mergeArrays22(int l, int n1, int s2, int n2) {
    int r=s2+n2;
    int i, j, k; 
	
	/* create temp arrays */
	int L[n1], R[n2]; 

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[s2 + j]; 

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2) { 
		if (L[i] <= R[j]) { 
			arr[k] = L[i]; 
			i++; 
		} 
		else { 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	/* Copy the remaining elements of L[], if there 
	are any */
	while (i < n1) { 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	/* Copy the remaining elements of R[], if there 
	are any */
	while (j < n2) { 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
}
void *mergeSort(void *d) {
  struct data *d1;
  d1 = (struct data *)d;
  // uncomment the following lines to gain insignt and see how this algorithm works
  // printf("created  thread with id = %ld \n", pthread_self());
  // printf("thread will start sorting from index = %d \n", d1->start);
  // printf("It will sort this many elements = %d \n\n", d1->num);
  // if array has only 1 element then it is already sorted
  if (d1->num > 1) {
    pthread_t tid1, tid2; /* the thread identifier */
    pthread_attr_t attr;  /* set of thread attributes */

    // initialise struct
    data t1, t2;
    t1.start = d1->start;
    t1.num = d1->num / 2;
    t2.start = d1->start + d1->num / 2;  // start location is same as index
    t2.num = d1->num - t1.num;
    // make more child threads

    pthread_create(&tid1, NULL, mergeSort, (void *)&t1);
    pthread_create(&tid2, NULL, mergeSort, (void *)&t2);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    mergeArrays22(t1.start, t1.num, t2.start, t2.num);
  }
}
int main(int argc, char *argv[]) {
  // take inputs
  int n = atoi(argv[1]);

  // printf("created main thread with id = %ld \n", pthread_self());
  // printf("thread will start sorting from index = %d \n", 0);
  // printf("It will sort this many elements = %d \n\n", n);
  // initalize arrays
  for (int i = 0; i < n; ++i) {
    arr[i] = atoi(argv[i + 2]);
    arr2[i] = arr[i];
  }

  printf("Given array is \n");
  printArray(arr, n);
  // divide in 2
  pthread_t tid1, tid2; /* the thread identifier */
  pthread_attr_t attr;  /* set of thread attributes */

  // initialise struct

  data t1, t2;
  t1.start = 0;
  t1.num = n / 2;
  t2.start = n / 2;     // no need to add +1 because array index starts from 0
  t2.num = n - t1.num;  // all remaining elements

  pthread_create(&tid1, NULL, mergeSort, (void *)&t1);
  pthread_create(&tid2, NULL, mergeSort, (void *)&t2);
  // wait for child threads to get sorted
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  // megre them
  mergeArrays22(t1.start, t1.num, t2.start, t2.num);

  // show them

  printf("\nSorted array is \n");
  printArray(arr, n);
  return 0;
}