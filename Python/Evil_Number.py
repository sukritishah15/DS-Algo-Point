# Python program to check if a number is 
# Evil number or Odious number 

# returns number of 1s from the binary number 
def count_one(n): 
    c_one = 0
    while n != 0: 
        rem = n % 10
        
        # Counting 1s 
        if rem == 1: 
            c_one = c_one + 1
        n = n / 10
        
    return c_one 

# Check if nnumber is evil or not 
def checkEvil(n): 
    i = 0
    binary = 0
    
    # Converting n to binary form 
    while n != 0: 
        r = n % 2
        # Calculating Remainder 
        # Storing the remainders in binary 
        # form as a number 
        binary = binary + r*(int(10**i))
        n = n / 2
        
    # Calling the count_one function to count 
    # and return number of 1s in bin 
    n_one = count_one(binary) 
    if n_one % 2 == 0: 
        return True
    return False
    
# Driver Code 
num = 32
check = checkEvil(num) 
if check: 
    print (num, "is Evil Nummber")
else: 
    print (num, "is Not a evil  Number")		
         


         
