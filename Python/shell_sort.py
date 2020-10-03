# Shell sort in python
def shellSort(array, n):
    # Rearrange elements at each n/2, n/4, n/8, ... intervals
    interval = n // 2
    while interval > 0:
        for i in range(interval, n):
            temp = array[i]
            j = i
            while j >= interval and array[j - interval] > temp:
                array[j] = array[j - interval]
                j -= interval

            array[j] = temp
        interval //= 2

arr = list(map(int, input().split()))
size = len(arr)
shellSort(arr, size)
print('Sorted Array in Ascending Order:')
print(arr)

"""
input and output
1 3 2 5
Sorted Array in Ascending Order:
[1, 2, 3, 5]
time O(nlogn)
space O(1)
"""