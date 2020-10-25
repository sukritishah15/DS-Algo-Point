# Python program for implementation of MergeSort

# Merge two subarrays of arr[].
# 1st subarray is arr[l..mid]
# 2nd subarray is arr[mid+1..r]


def merge(arr, l, mid, r):
    n1 = mid - l + 1
    n2 = r - mid

    # create temp arrays
    Left = [0] * (n1)
    Right = [0] * (n2)

    # Copy arr to temp arrays L[] and R[]
    for i in range(0, n1):
        Left[i] = arr[l + i]

    for j in range(0, n2):
        Right[j] = arr[mid + 1 + j]

    # Merge the temp arrays back into original array arr[l..r]
    i = 0     # 1st index of first subarray
    j = 0     # 1st index of second subarray
    k = l     # 1st index of merged subarray

    while i < n1 and j < n2:
        if Left[i] <= Right[j]:
            arr[k] = Left[i]
            i += 1
        else:
            arr[k] = Right[j]
            j += 1
        k += 1

    # Copy the remaining elements of L[], if there are any
    while i < n1:
        arr[k] = Left[i]
        i += 1
        k += 1

    # Copy the remaining elements of R[], if there are any
    while j < n2:
        arr[k] = Right[j]
        j += 1
        k += 1


def mergeSort(arr, l, r):
    if l < r:

        # Same as (l+r)//2, but we avoid overflow for large l and h
        mid = (l+(r-1))//2

        # Sort first and second half
        mergeSort(arr, l, mid)
        mergeSort(arr, mid+1, r)
        merge(arr, l, mid, r)


# Driver code
arr = [12, 11, 13, 5, 6, 7]
n = len(arr)
print("Input array:")
for i in range(n):
    print("%d" % arr[i]),

mergeSort(arr, 0, n-1)
print("\n\nSorted array:")
for i in range(n):
    print("%d" % arr[i]),

# Sample input and output 1
# Input array:
# 12 11 13 5 6 7

# Sorted array:
# 5 6 7 11 12 13

# Sample input and output 2
# Input array:
# 15 17 32 3 8 9

# Sorted array:
# 3 8 9 15 17 32

# Time complexity : O(nlog(n))
# Space complexity : O(n)
