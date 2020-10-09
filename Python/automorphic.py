# Automorphic Number: The last digits of thr square of the number is equal to the digit itself

n=int(input("Enter the number: "))
sq= n**2

l=len(str(n))

ld=sq%pow(10,l)

if (ld==n):
    print("Automorphic Number")
else:
    print("Not a automorphic number")


    """
    I/O

Enter the number: 25  
Automorphic Number

Enter the number: 12
Not a automorphic number

Time complexity- O(1)
Space Complexity- O(1)

    """