# Function to print maximum number 
def Maximum(num): 
  
    # Hashed array to store count of digits 
    count = [0 for x in range(10)] 
  
    # Converting given number to string 
#     string = str(num) 
  
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
# num = 38293367
print(Maximum(num))


"""
Enter the number
38293367
98763332
Time O(nlog n)
Space O(1)
"""