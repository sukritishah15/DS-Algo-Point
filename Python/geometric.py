# Find Sum of Geometric Progression Series

import math
##User input
first = int(input("Please Enter First Number of the Geometric Progression: : "))
n = int(input("Please Enter the Total Numbers present in the Geometric Progression: : "))
ratio = int(input("Please Enter the Common Ratio : "))

total = (first * (1 - math.pow(ratio, n ))) / (1- ratio)
nth = first * (math.pow(ratio, n - 1))
##Sum of the GP
print("The Sum of Geometric Progression : " , total)
##nth Term in the GP
print("The nth Term in the Geometric Progression : " , nth)


""""
Example:
Please Enter First Number of the Geometric Progression: : 
6
Please Enter the Total Numbers present in the Geometric Progression: : 
5
Please Enter the Common Ratio : 
2
The Sum of Geometric Progression :  186.0
The nth Term in the Geometric Progression :  96.0

.....

Time Complexity - O(1)
Space Complexity - O(1)

"""