
# Program to find the Evil Number .
#Taking input from the user
n=int(input())
i=0
binry=0
while(n!=0):
    remainder=n%2
    binry=binry+remainder*(int(10**i))
    n=n//2
#Counting number of 1's
while(binry!=0):
    rem=binry%2
    if rem==1:
        count=count+1
    binry=binry//10
if count%2==0:
    print("Evil Number.")
else:
    print("Not an evil number.")

"""An evil number is the number which has even number of 1's in its binary equivalent.
Sample input:256
Sample output:Not a evil number


"""
         
