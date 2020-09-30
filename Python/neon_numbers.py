# Neon number --> If the sum of digits of the squared numbers are equal to the orignal number , the numeber is said to be Neon number. Example 9
ch=int(input("Enter 1 to do it with loop and 2 without loop :\n"))
n= int(input("Enter the number :\n"))
def number(n):

    sq= n**2

    digisum=0

    while sq>0:

        r=sq%10

        digisum = digisum + r
        sq=sq//10

    if (n==digisum):
        print("The number is neon number")
    else:
        print("Not a neon mumber")


# Without Loop

def number2(n):

    sq=n*n
    r=sq%10
    q=sq//10

    tocheck=r+q

    if n==tocheck:
        print("It is a Neon Number")

    else:
        print("Not a neon number")


if ch==1:
    number(n)
elif ch==2:
    number2(n)
else:
    print("Enter correct choice")

"""
Time complexity - O(1)
Space complexity - O(1)

I/o-- 
Enter 1 to do it with loop and 2 without loop :
2
Enter the number :
9
It is a Neon Number

Explanation

Input n: 9
sq=81
r=1
q=8
tocheck=8+1 =>9
Output
if 9 == 9 ==> Neon number 
"""
