# Problem statement 
# Given two variables n1 and n2. The task is to swap the values of both the variables without using third variable.

# Sample input
# 10
# 20

# Sample output
# Before swapping: 
# Value of x :  10  and y :  20
# After swapping: 
# Value of x :  20  and y :  10   

# We can solve this problem in python by four methods 
# Method 1. Using built-in method
x = input()
y = input()
  
print ("Before swapping: ") 
print("Value of x : ", x, " and y : ", y) 
  
# code to swap 'x' and 'y' 
x, y = y, x  # built in method
  
print ("After swapping: ") 
print("Value of x : ", x, " and y : ", y) 


# Method 2. Using Bitwise XOR operator
x = input()  
y = input() 
  
print ("Before swapping: ") 
print("Value of x : ", x, " and y : ", y) 

# Swap code 
x ^= y  
y ^= x  
x ^= y  
  
print ("After swapping: ") 
print("Value of x : ", x, " and y : ", y) 


# Method 3. Using Addition and Subtraction Operators
x = input()
y = input()
  
print ("Before swapping: ") 
print("Value of x : ", x, " and y : ", y) 
  
# Swap code 
x = x + y  
y = x - y  
x = x - y 
  
print ("After swapping: ") 
print("Value of x : ", x, " and y : ", y) 


# Method 4. Using Division and Multiplication Operators
x = input()
y = input()
  
print ("Before swapping: ") 
print("Value of x : ", x, " and y : ", y) 
  
# Swap code 
x = x * y   
y = x / y  
x = x / y 
  
print ("After swapping: ") 
print("Value of x : ", x, " and y : ", y) 

# Time complexity : O(1)
# Space complexity : O(1)
# Note = You can use any of these methods 