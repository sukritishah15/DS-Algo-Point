def insertionSort(array):

    for step in range(1, len(array)):
        key = array[step]
        j = step - 1
        
        # Compare key with each element on the left of it until an element smaller than it is found
        # For descending order, change key<array[j] to key>array[j].        
        while j >= 0 and key < array[j]:
            array[j + 1] = array[j]
            j = j - 1
        
        # Place key at after the element just smaller than it.
        array[j + 1] = key


        
data = list(map(int, input().split(",")))
insertionSort(data)
print('Sorted Array in Ascending Order:')
print(data)

"""
I/O:
Enter Data: 9, 5, 1, 4, 3
Sorted Array in Ascending Order:
[1, 3, 4, 5, 9]

Complexities:
Time Complexities:
Worst Case Complexity: O(n^2)
Best Case Complexity: O(n)
Average Case Complexity: O(n^2)

Space Complexities:
Space complexity is O(1) because an extra variable key is used.
"""
