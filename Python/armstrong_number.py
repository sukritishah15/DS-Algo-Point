n = int(input())
l = len(str(n))
s = 0
temp = n
while temp > 0:
    s += (temp%10) ** l
    temp //= 10

if n == s:
    print("Armstrong number")
else:
    print("Not an armstrong number")

'''
Check whether a number entered by the user is Armstrong or not.

A positive integer of n digits is called an Armstrong Number (of order n) if:
abcd.. = a^n + b^n + c^n + d^n + ...

Sample Input:
n = 153

Sample Output:
Armstrong number

Explanation: 153 is an armstrong number because, 153= 1x1x1 + 5x5x5 + 3x3x3 i.e. 1^3+5^3+3^3 = 153.

Time complexity : O(log N)
Space complexity: O(1)
'''