#Python program to check if a number is Abundant or not

def is_abundant(n):
  s=0
  for i in range(1,n): # This for loop calculates the sum of the divisors of a number
    if n%i==0:
      s = s + i

  a = s-n  #Calculates the difference between the sum of the divisors and the given number

  if s > n:
    print(n,"is an Abundant Number and the Abundance is",a)
  else :
    print(n,"is not an Abundant Number")

#User Input:
print("Enter the number to check:")
n = int(input())

is_abundant(n)


'''
Explanation:
A number is said to be abundant if the sum of the divisors of the
number is greater than the number itself. And the differnce between these two
values is called the abundance of an abundant number.

Examples of Abundant Numbers:
->12:
  Divisors of 12: 1,2,3,4,6
  Sum of divisors: 16
  Abundance: 16-12 = 4

 ->18:
   divisors of 18: 1,2,3,6,9
   Sum of divisors: 21
   Abundance: 21-18 = 3

Sample Input:
Enter the Number to check:
12

Sample Output:
12 is an Abundant Number and the Abundance is 4

Time Complexity : O(n)
Space Complexity : O(1)

'''
