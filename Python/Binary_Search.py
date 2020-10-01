'''
Binary Search: =>  Search a sorted array by repeatedly dividing the search interval in half. 
Begin with an interval covering the whole array. If the value of the search key is less 
than the item in the middle of the interval, narrow the interval to the lower half. 
Otherwise narrow it to the upper half. Repeatedly check until the value is found or the interval is empty.


''Defination refer by W3School.com''


'''




size = int(input("Enter a Element of array"))
array = []

print("Enter a elements in sorted order")

for i in range(size):
    temp = int(input())
    array.append(temp)

array.sort()

low = 0
high = size-1

search = int(input("Enter a number to be searched"))

while low <= high:

    mid = low + (high-low)//2

    if array[mid] == search:
        print("Element found at " + str(mid) + " index")
        break
    elif array[mid] < search:
        low = mid+1

    else:
        high = mid-1
else:
    print("Element are not present")

print("Index start with 0 ")