def insertion_sort(arr):
    comparisons = 0
    moves = 0
    
    for step in range(1,len(arr)):
        key = arr[step]
        i = step - 1
        
        while i >= 0 and key < arr[i]:
            arr[i + 1] = arr[i]
            i = i - 1
            comparisons += 1
            
        if arr[i + 1] != key:
        	arr[i + 1] = key
        	print(arr)
        	moves += 1
    return (comparisons, moves)

data = [6,2,4,3,5,1,7]
comparisons, moves = insertion_sort(data)
print(f'Sorted Array in Ascending Order: {data}')
print(f'Sorted in {moves} moves and {comparisons} comparisons')


# Sample input [6,2,4,3,5,1,7]
# Sample Output
	# [2, 6, 4, 3, 5, 1, 7]
	# [2, 4, 6, 3, 5, 1, 7]
	# [2, 3, 4, 6, 5, 1, 7]
	# [2, 3, 4, 5, 6, 1, 7]
	# [1, 2, 3, 4, 5, 6, 7] 
	# Sorted Array in Ascending Order: [1, 2, 3, 4, 5, 6, 7]
	# Sorted in 5 moves and 10 comparisons

# Space Complexity: O(n)

# Time complexity
    # Worst case: O(n^2)
    # Best case: O(n)
    # Average case: O(n^2)
