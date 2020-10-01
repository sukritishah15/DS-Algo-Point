# Ternary search function
def TernarySearch(l, r, key, arr): 

    if (r >= l): 

        # Find the mid1 and mid2 
        mid1 = l + (r - l) //3
        mid2 = r - (r - l) //3

        # Check if key is present at mid1 
        if (arr[mid1] == key):
            return mid1 

        # Check if key is present at mid2
        elif (arr[mid2] == key):
            return mid2 
        
        # Check if key is present before mid1
        elif (key < arr[mid1]):  
            return TernarySearch(l, mid1 - 1, key, arr) 
        
        # Check if key is present after mid2 
        elif (key > arr[mid2]):  
            return TernarySearch(mid2 + 1, r, key, arr) 
        
        # Check if key is present between mid1 and mid2
        else:  
            return TernarySearch(mid1 + 1, mid2 - 1, key, arr) 
    
    # key is not present in the array      
    return -1

n = int(input("Enter the number of elements\n"))

# Mapping each element of input into integer and making a list of it

arr = list(map(int, input("Enter {} elements\n".format(n)).split()))

# sorting the list
arr.sort()

# assigning the start and end variable
l = 0
r = n-1

# Inputting key to be searched from the user
key = int(input("Enter the key to be found\n"))

# Calling the function and assigning index returned to a variable
i = TernarySearch(l, r, key, arr) 

# printing the output
print(key, "is found at index", i) 

"""input and output
Enter the number of elements
4
Enter 4 elements
1 3 2 4
Enter the key to be found
3
3 is found at index 2"""

#time complexity O(logN)
#space complexity O(1)

