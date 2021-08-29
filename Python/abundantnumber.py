import math

def getSum(n) :
	sum = 0


	i = 1
	while i <= (math.sqrt(n)) :
		if n%i == 0 :


			if n/i == i :
				sum = sum + i
			else :
				sum = sum + i
				sum = sum + (n / i )
		i = i + 1

	sum = sum - n
	return sum

def checkAbundant(n) :


	if (getSum(n) > n) :
		return 1
	else :
		return 0

if(checkAbundant(12) == 1) :
	print "YES"
else :
	print "NO"

if(checkAbundant(15) == 1) :
	print "YES"
else :
	print "NO"
