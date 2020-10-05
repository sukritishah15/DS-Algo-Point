def rotatethearray(array, d):
    array[0:d] = reversed(array[0:d])
    array[d: ] = reversed(array[d: ])
    array.reverse()
    print(array)


print("enter the array of numbers:", end=" ")
array = [int(i) for i in input().split()]
print()
print("enter the value of d:", end=" ")
d = int(input())
rotatethearray(array, d)

#In this algo we first reversed the elements upto index D (excluded)
#then we reversed the elements from Dth index to the end
#finally we reversed the entire array
#doing so, our array gets reversed by D elements clockwise
# Input: 1 2 3 4 5
# D = 3
# Output: 4 5 1 2 3
# T.C: O(n)
# S.C: O(n)

