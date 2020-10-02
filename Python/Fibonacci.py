
# # Program to display the Fibonacci sequence up to n-th term

n = int(input("Please Enter the total number of terms : "))

# first two terms
n1, n2 = 0, 1
temp = 0

# check if the number of terms is valid
if n <= 0:
    print("Please enter a positive integer")
elif n == 1:
    print("Fibonacci sequence upto :",n,":")
    print(n1)
else:
    print("Fibonacci sequence:")
    while temp < n:
        print(n1)
        n3 = n1 + n2
        # Changing values of n1 and n2
        n1 = n2
        n2 = n3
        temp += 1




"""""

Example:
Please Enter the total number of terms : 
11
Fibonacci sequence:
0
1
1
2
3
5
8
13
21
34
55

            ........

Time Complexity :- O(n)
Space Complexity :- O(1)

""""