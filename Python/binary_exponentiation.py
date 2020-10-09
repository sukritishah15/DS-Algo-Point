number = int(input("Please enter number you want to to elevate : "))
power = int(input("Please enter the power : "))

binary = bin(power)
binary = str(binary)[2:]

prod = 1
index = 0
for c in reversed(binary):
    if c == '1':
        prod *= pow(number, pow(2, index))
    index += 1

print(prod)

'''
Compute the binary exponentiation

3^13=3^(1101)2=3^8⋅3^4⋅3^1

Sample Input:
number = 3
power = 13

Sample Output:
1594323 

Time complexity : O(log N)
Space complexity: O(1)
'''