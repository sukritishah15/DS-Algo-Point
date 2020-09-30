n = int(input("Enter number of elements:"))
print("Enter elements:")
array = []
for i in range(n):
    array.append(int(input()))
for i in range(n-1):
    for j in range(n-1-i):
        if array[j] > array[j+1]:
            temp = array[j]
            array[j] = array[j + 1]
            array[j + 1] = temp
print("Sorted array is:")
print(array)


"""
Problem : Sort the given array using bubble sort.

Traverse through all elements of array and in each pass place the element having maximum value at last of unsorted array. After each pass length of unsorted elements decreases hence we don't have to traverse all elements in every pass.

Sample I/O:

Enter number of elements:5
Enter elements:
5
4
3
2
1
Sorted array is:
[1, 2, 3, 4, 5]

Enter number of elements:4
Enter elements:
2
4
1
3
[1, 2, 3, 4]

Time complexity: O(n^2) (worst)
Space complexity: O(1)
"""
