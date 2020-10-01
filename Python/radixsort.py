
def countingSort(arr, exp1): 

	n = len(arr) 

	output = [0] * (n) 

	count = [0] * (10) 

	for i in range(0, n): 
		index = (arr[i]/exp1) 
		count[ (index)%10 ] += 1

	for i in range(1,10): 
		count[i] += count[i-1] 

	i = n-1
	while i>=0: 
		index = (arr[i]/exp1) 
		output[ count[ (index)%10 ] - 1] = arr[i] 
		count[ (index)%10 ] -= 1
		i -= 1

	i = 0
	for i in range(0,len(arr)): 
		arr[i] = output[i] 

def radixSort(arr): 

	max1 = max(arr) 
	exp = 1
	while max1/exp > 0: 
		countingSort(arr,exp) 
		exp *= 10

radixSort(arr) 

for i in range(len(arr)): 
	print(arr[i]), 



"""
Problem : Sort the given array using radix sort.

Sort the elements by first grouping the individual digits of the same place value. Then, sort the elements according to their increasing/decreasing order.

Sample I/O:

INPUT:
121
432
564
23
1
45
788
Sorted Array in descending order is
[1, 23, 45, 121, 432, 564, 788]


Time complexity: O(nk) (worst)
Space complexity: Ω(nk) (best)
"""
