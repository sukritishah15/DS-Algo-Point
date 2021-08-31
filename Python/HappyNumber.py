# Python program to check if a number is happy or not:

# funtion to get sum of squares of the digits of a number:
def ssd(n):
    a = b = 0;
    while(n > 0):
        a = n%10
        b += a*a
        n //= 10
    return b

# User input:
print("Enter Number to Check:")
n = int(input())
h = n;

while(h != 1 and h != 4):
    h = ssd(h)

if(h == 1):
    print(n,"is a happy number")
elif(h == 4):
    print(n,"is not a happy number")

'''
Explanation:
A happy number is a number which eventually reaches 1 when replaced
by the sum of the square of each digit. All Non happy numbers eventually
become 4 and get stuck in an infinite cycle, therefore if a number reaches 4
anytime in the cycle it is not a happy number

Examples of Happy Numbers:
-> 100 = 1*1 + 0*0 +0*0 = 1
-> 13 = 1*1 + 3*3 = 10, 10 = 1*1 + 0*0 = 1
-> 19 = 1*1 + 9*9 = 82, 82 = 8*8 + 2*2 = 68, 68 = 6*6 + 8*8 = 100, 100 = 1*1 + 0*0 + 0*0 =1

Sample Input:
Enter Number to Check:
13

Sample Output:
13 is a happy number

Time Complexity : O(log N)
Space Complexity : O(log N)
'''
