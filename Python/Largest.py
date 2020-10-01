# Function to print maximum number 
def Maximum(num): 
    # Hashed array to store count of digits 
    count = [0 for x in range(10)] 

    # Updating the count array 
    for i in range(len(num)): 
        count[int(num[i])] = count[int(num[i])] +  1

    # Result stores final number 
    result = 0
    multiplier = 1

    # traversing the count array 
    # to calculate the maximum number 
    for i in range(10): 
        while count[i] > 0: 
            result = result + ( i * multiplier ) 
            count[i] = count[i] - 1
            multiplier = multiplier * 10

    # return the result 
    return result 

num = input("Enter the number\n")
print(Maximum(num))

# Input and Output
# Enter the number
# 38293367
# 98763332

# Time complexity is O(n)