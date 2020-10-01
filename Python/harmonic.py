# Python program to find the sum of harmonic series 

def sum(n): 
	i = 1
	s = 0.0
	for i in range(1, n+1): 
		s = s + 1/i; 
	return s; 

n = int(input("First term"))
print("Sum is", sum(n)) 

""""
Time Complexity :- O(logn)
Space Complexity :- O(n)

Input: n=5 
Output: Sum is 2.283333333333333
"""