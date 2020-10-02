# Function to find HCF the Using Euclidian algorithm
def gcd(x, y):
   while(y):
       x, y = y, x % y
   return x

num1 = int(input())
num2 = int(input())

gcd = gcd(num1, num2)
print("The GCD is", gcd)

"""
4
6
The H.C.F. is 2

"""
"""
time complexity O(logn)
space complexity O(1)
"""