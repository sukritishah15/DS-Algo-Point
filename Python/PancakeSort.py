def flip(array, j):
    start = 0
    while(start<j):
        temp = array[start]
        array[start] = array[j]
        array[j] = temp
        start = start +1
        j -= 1

def findMaxIdx(array, n):
    mi = 0
    for i in range(n):
        if (array[i] > array[mi]):
            mi = i
    return mi
    
n = int(input("Enter number of elements:"))
print("Enter elements:")
array = []
for i in range(n):
    array.append(int(input()))
x = n
while (x>1):
    j = findMaxIdx(array, x)
    if (j != x-1):
        flip(array, j)
        flip(array, x-1)
    x -= 1
    
print("Sorted array is:")
print(array)

"""
Pancake Sort in python.

Sample I/O:

Enter number of elements:5
Enter elements:
12
43
13
56
2
Sorted array is:
[2, 12, 13, 43, 56]

Enter number of elements:4
Enter elements:
45
44
43
1
Sorted array is:
[1, 43, 44, 45]

Time Complexity: O(n^2)
Space Complexity: O(1)

"""
