n = int(input()) 
  
ls = list(map(int,input().strip().split()))[:n] 



ls.sort()

sum = 0 

for x in ls:
	sum = sum + x

print(sum/n) 

if(n % 2 == 1):
	print(ls[n//2])
else:
	print((ls[n//2] + ls[(n//2)]) / 2) 

'''
Time complexity: O(n) 
Space complexity: O(1)

Imput format:
first line consisit of n
second line consist n integers
Output format:
first line consists of mean 
second line consistes of median

Sample Input:
3
1 5 10
Output:
5.333333333333333
5
'''