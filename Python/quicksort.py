# Python program for implementation of Quicksort Sort
# This function takes last element as pivot, places
# the pivot element at its correct position in sorted
# array, and places all smaller (smaller than pivot)
# to left of pivot and all greater elements to right
# of pivot


def partition(arr, low, high):
    i = (low-1)         # index of smaller element
    pivot = arr[high]     # pivot
 
    for j in range(low, high):
 
        # If current element is smaller than or
        # equal to pivot
        if arr[j] <= pivot:
 
            # increment index of smaller element
            i = i+1
            arr[i], arr[j] = arr[j], arr[i]
 
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return (i+1)


# a[] is the array to be sorted,
# low is the Starting index,
# high is the Ending index

# Function to do Quick sort
def quickSort(a, low, high):
	if len(a) == 1:
		return a
	if low < high:

		# pi is partitioning index
		
		pi = partition(a, low, high)		
		quickSort(a, low, pi-1)#this is partition on left side
		quickSort(a, pi+1, high)#this is partition on right side



n=int(input('enter the length of array '))
print('enter the elements of the array ')
a=[]# a new dynamic array
for i in range(n):
    a.append(int(input()))
print('unsorted array is')
print(a)
quickSort(a, 0,len(a)-1)
print("Sorted array is:")
print(a)


##    enter the length of array 5
##    enter the elements of the array
##    10
##    6
##    8
##    2
##    4
##    unsorted array is
##    [10, 6, 8, 2, 4]
##    Sorted array is:
##    [2, 4, 6, 8, 10]
##
