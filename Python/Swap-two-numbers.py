# Problem statement 
# write a program to swap two numbers without using third variable 

x = input()
y = input()
  
print ("Before swapping: ") 
print("Value of x : ", x, " and y : ", y)  

x, y = y, x
 
print ("After swapping: ") 
print("Value of x : ", x, " and y : ", y) 

# sample input 
# 10 
# 20

# sample output 
# Before swapping: 
# Value of x :  10  and y :  20
# After swapping: 
# Value of x :  20  and y :  10

# Time complexity : O(1)
# space complexity : O(1)