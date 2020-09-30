t1 = 1
t2 = 2
n = 4
print(t1*((t2//t1)**(n-1)))

""" 
 sample input 
 Let the first term be 1 and second term be 2. Also let the value of n be 4
 The programs calculates the nth term by using formula of gp i.e. ar^(n-1) where r = common ratio = t2/t1 in this case.
 Output is 8.
 Time Complexity is O(1) and space complexity is O(1)
 
"""
