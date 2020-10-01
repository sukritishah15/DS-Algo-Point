def selection_sort(arr):
    for i in range(len(arr)):
        min_index = i

        for j in range(i+1, len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j
        
        arr[i], arr[min_index] = arr[min_index], arr[i]

n = int(input("Enter number of elements: "))
print("Enter elements:")
nums = []
for i in range(n):
    nums.append(int(input()))
    
selection_sort(nums)
print("Sorted Array:")
print(nums)


"""
Sample I/O:

Enter number of elements: 5
Enter elements:
5
4
3
2
1
Sorted Array:
[1, 2, 3, 4, 5]


Time Complexity: O(n^2) for Best Case, Average Case & Worst Case
Space Complexity: O(1)
Stable: No
"""
