import math
# taking input 
n  = int(input('Write a number\n'))

'''making a list named primes initialize primes with 1 only 
here 1 represent the value is prime and we believe all value are prime initially'''
primes = [1]*(n+1)

# making first and second values as 0 as  0, 1 is not a prime and start by checking 
# from 2
primes[0] = 0
primes[1] = 0

'''
looping through 2,sqrt(n)+1 as every number 
comes with 2 factor if first factor is seen then
we don't have to look for second one
in second loop we are initialize all multiple of 
'''
# i in first loop
for i in range(2, int( math.sqrt(n)+1 ) ):
    if primes[i] == 1:
        for  j in range(i*i, n+1, i):
            primes[j] = 0

# printing all primes from 2 to n 
for i in range(len(primes)):
    if primes[i] == 1:
        print(i,end = " ")

# Checking if a particular value is prime or not
check = int(input('\nWrite a number to check whether it is prime or not until '+str(n)+ '\n'))
if primes[check] == 1:
    print(check,'is a prime number')
else:
    print(check,'is not a prime number')

'''
Complexity :-

Time  ==> O(n*logn)

Space ==> O(n)

I/O ---->
Write a number
10
2 3 5 7
Write a number to check whether it is prime or not until 10
3
3 is a prime number

# Explaination
We provide input to 10 and our code give all prime till 10(inclusive)
and at next line we take input to check if 3 is prime or not
'''
