# Sum of harmonic series 

def sumHarmonic(n): 
	i = 1
	sum = 0.0
	for i in range(1, n+1): 
		sum = sum + 1/i; 
	return sum; 

n = int(input("First term :"))
print("Sum of the Harmonic Series :", sumHarmonic(n)) 

""""
Example:

First term :
6
Sum of the Harmonic Series : 2.4499999999999997

            .........

Time Complexity :- O(logn)
Space Complexity :- O(n)

"""