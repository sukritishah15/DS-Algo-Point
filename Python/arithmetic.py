# Sum of Arithmetic Progression Series

first = int(input("Please Enter First Number of an A.P: : "))
n = int(input("Please Enter the Total Numbers in this A.P: : "))
diff = int(input("Please Enter the Common Difference : "))

total = (n * (2 * first + (n - 1) * diff)) / 2
nth = first + (n - 1) * diff
i = first
print("The nth Term of Arithmetic Progression Series : " , nth)
print("The Sum of Arithmetic Progression : ")
while(i <= nth):
    if(i != nth):
        print("%d + " %i, end = " ")
    else:
        print("%d = %d" %(i, total))
    i = i + diff


"""""
Example:
Please Enter First Number of an A.P: : 
4
Please Enter the Total Numbers in this A.P: : 
5
Please Enter the Common Difference : 
7
The nth Term of Arithmetic Progression Series :  32
The Sum of Arithmetic Progression : 
4 +  11 +  18 +  25 +  32 = 90
                ..............
                
Time Complexity:- O(1)
Space Complexity:- O(1)
"""
