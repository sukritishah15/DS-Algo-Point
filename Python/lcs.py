def pre_compute_hash(text, m, x):
	n = len(text)+1
	H =[0]*n
	for i in range(1,n):
		H[i] = (x*H[i-1] + ord(text[i-1]))
		if(H[i]>=m):
			H[i] = H[i] % m
	return H

def present(s,t,length,H1,H2,powers,m,ans):
	y = powers[length]
	values = {}
	for i in range(0, len(s) - length + 1):
		val1 = (H1[i+length] - y*H1[i])
		if(val1 >= m or val1 < 0):
			val1 = val1 % m
		values[val1]=i
	for j in range(0, len(t) - length + 1):
		val2 = (H2[j+length] - y*H2[j])
		if(val2 >= m or val2 < 0):
			val2 = val2 % m
		try:
			i = values[val2]
			return True,[i,j,length]
		except:
			continue
	return False, [0,0,0]



def bsearch(s,t,l,r,H1,H2,powers,m):
	prev = [0,0,0]
	found,ans = present(s,t,1,H1,H2,powers,m,prev)
	if(not found):
		return ans
	ans = prev
	while r >= l:
		mid = (l+r)//2
		found,ans = present(s,t,mid,H1,H2,powers,m,ans)
		if(ans[2]< prev[2]):
			ans = prev
		if(found):
			l=mid+1
		else:
			r=mid-1
		prev = ans
	return ans
	


def solve(s ,t):
	m =10**11 + 7
	x = 123
	powers = [1]
	s = list(str(s))
	t = list(str(t))
	y=1
	if(s==t):
		return [0,0,len(s)]
	for i in range(0,max(len(s),len(t))+1):
		y = y*x
		if(y>m):
			y = y%m
		powers.append(y)
	H1 = pre_compute_hash(s, m, x)
	H2 = pre_compute_hash(t, m, x)
	ans = bsearch(s,t,0,min(len(s),len(t)),H1,H2,powers,m)
	return ans




string1 = input()
string2 = input()
ans = solve(string1,string2)
if(ans[2]==0):
	print("No common subsequence")
else:
	for i in range(ans[0],ans[0] + ans[2]):
		print(string1[i],end="")


""" 
Problem : Find the longest common subsequence in the given two string

Sample Input 1 : 
	voteforme
	votefromme
Ouptput :
	votef

Sample Input 2 : 
	iamsad
	your
Ouptput :
	No common subsequence



s = length of small string
t = length of second string
n = length of longest common subsequence


Time Complexity :- O((s+t-n)logs) 
Space Complexity :- O(s + t)



Working for the Program - 

1) We use the following Hash Function to find the Hash value
			H(text) = sum{(t0*x^0)%m + (t1*x^1)%m + ... + (tn*x^n-1)%m}%m
			where m is a very large prime number and 
				  x is a number between 1 and m-1
			Also H[i+1] can be found with  x*H[i] + ord(text[i]) helping us save time

2) We compute the hash values of all prefixes of both the strings and store them in H1 and H2.
			Suppose a string is "hello"  then store the hash value of all the prefixes i.e. "h","he","hel","hell","hello" in list H1.

3) No perform binary search for numbers between 0 and minimum of length od both the strings.
		Why Binary Search? Suppose there are two string od length 9 and 10, then the max length possible for substring is 9.
		If the substring with max length is of 7 ,then to find that we need 7 tries if we use linear search . i.e 1,2,3...7
		If we use binary search the the lengths to search will be 4,7 and we found the substring.
		Binary search reduces the search time to O(logn)

4) Check if a commom substring of given length exists or not.
		Hash Values of all substring of given length can be found using the pre-computed hash table of that string using the formula
											H = (H1[i+length] - (x^length)*H1[i] ) %m

5) Store this values in a dictionary will key as hash value and value as starting index of substring.
											values = {347347: 6,......}

6) Now repeat the same process on second string but compare its hash values if the first string to check if substrings match or not.
											H = (H2[i+length] - (x^length)*H2[i] ) %m
											if values[H] exists then we found a common subsequence of given length
7) Continue with Binary search.
											
											

"""