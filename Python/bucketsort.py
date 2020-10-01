
def bucketSort(array):
    bucket = []

    for i in range(len(array)):
        bucket.append([])

    for j in array:
        index_b = int(10 * j)
        bucket[index_b].append(j)

    for i in range(len(array)):
        bucket[i] = sorted(bucket[i])

    k = 0
    for i in range(len(array)):
        for j in range(len(bucket[i])):
            array[k] = bucket[i][j]
            k += 1
    return array


print("Sorted Array in descending order is")
print(bucketSort(array))



"""
Problem : Sort the given array using bucket sort.

Sort the elements by first dividing the elements into several groups or buckets. The elements inside each bucket are sorted using any of the suitable sorting algorithms or recursively calling the same algorithm.

Sample I/O:

INPUT:
3
4
5
2
1
Sorted Array in descending order is
[1, 2, 3, 4, 5]


Time complexity: O(n^2) (worst)
Space complexity: Ω(n+k) (best)
"""
