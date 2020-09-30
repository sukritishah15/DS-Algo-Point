import math
# taking input
n  = int(input())
# making a list named primes
    # initialize primes with 1 only 
# here 1 represent the value is prime 
primes = [1]*(n+1)

# making first and second values as 0
# as  0, 1 is not a prime and start by checking 
# from second value
primes[0] = 0
primes[1] = 0

# looping through 2,sqrt(n)+1 as every number 
# comes with 2 factor if first factor is seen then
# we don't have to look for second one
# in second loop we are initialize all multiple of 
# i in first loop
for i in range(2,int(math.sqrt(n)+1)):
    if primes[i] ==1:
    	for  j in range(i*i,n+1,i):
	    	primes[j] = 0

# printing all primes
for i in range(len(primes)):
    if primes[i] == 1:
        print(i,end = " ")