# Kadane's Algorithm gives the maximum sum of a subarray in the given array.
# This function takes a python list as argument and return a number which is the
# max sum of any subarray of this list
def kadanes_algorithm(arr):
    maxTillNow = float('-inf')
    maxHere = 0

    for i in range(len(arr)):
        maxHere += arr[i]
        if maxTillNow < maxHere:
            maxTillNow = maxHere
        if maxHere < 0:
            maxHere = 0

    return maxTillNow


print("Enter space seperated list of numbers: ")
arr = list(map(int, input().split()))
print(kadanes_algorithm(arr))
"""
    Time Complexity: O(n)
    Space Complexity: O(n)

    INPUT:
    1 4 -5 6 -1 -2 7 0
    OUTPUT:
    10
"""
