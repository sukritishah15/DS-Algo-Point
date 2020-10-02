def heapify(arr, n, i): 
	largest = i 
	l = 2 * i + 1	 # left = 2*i + 1 
	r = 2 * i + 2	 # right = 2*i + 2 

	'''
	See if left child of root exists and is 
	greater than root '''	
	if l < n and arr[i] < arr[l]: 
		largest = l 

	# See if right child of root exists and is 
	# greater than root 
	if r < n and arr[largest] < arr[r]: 
		largest = r 

	# Change root, if needed 
	if largest != i: 
		arr[i],arr[largest] = arr[largest],arr[i] # swap 

		# Heapify the root. 
		heapify(arr, n, largest) 

def heapSort(arr): 
	n = len(arr) 

	# Build a maxheap. 
	for i in range(n//2 - 1, -1, -1): 
		heapify(arr, n, i) 

	# One by one extract elements 
	for i in range(n-1, 0, -1): 
		arr[i], arr[0] = arr[0], arr[i] # swap 
		heapify(arr, i, 0) 

print('Enter a list of numbers')
arr = list(map(int,input().split()))
heapSort(arr) 
print('After performing heap sort')
for i in arr:
    print(i,end =' ')


'''
Time Complexity => O(nlogn)
Space complexity => O(1)
I/O =>

Enter a list of numbers
29 21 1 2 4 2 5 99 33 54 23
After performing heap sort
1 2 2 4 5 21 23 29 33 54 99

'''
