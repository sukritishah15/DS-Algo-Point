import math
n = int(input('Enter n: '))
r = int(input('Enter r: '))
print(int(math.factorial(n)/math.factorial(n-r)))  # P(n,r)=n!/(n-r)!
# C(n,r)=n!/((n-r)!*(r!))
print(int(math.factorial(n)/(math.factorial(r)*math.factorial(n-r))))


# Sample Input
# Enter values of (n,r) for P(n,r) and C(n,r)
# 10 3
# Sample Output
# 720           (Permutation)
# 120           (Combination)
# ______________________________________________
# Time Complexity:O(n)
# Space Complexity:O(n)
