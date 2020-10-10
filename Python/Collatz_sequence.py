# problem statement: 
# Starting with any positive integer N, Collatz sequence is defined corresponding to n as the numbers formed by the following operations :
# If n is even, then n = n / 2.
# If n is odd, then n = 3*n + 1.
# Repeat above steps, until it becomes 1.


def printCollatz(n): 
    while n != 1: 
        print(n, end = ' ') 

        if n & 1: 
            n = 3 * n + 1 
        else: 
            n = n // 2  
    print(n) 

x = int(input()) 
printCollatz(x) 


# sample input: 
# 6

# sample output:
# 6 3 10 5 16 8 4 2 1

# There is no specific time of computing the collatz sequence of each numbers, so Time complexity is NA.
# Time complexity : NA
# Space complexity : O(1)