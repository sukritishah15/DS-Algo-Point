function isprime(n)
		{ var count=0;
			if(n==1)
				return 0;
			else
				for(let i=1;i<=n/2;i++)
				{
					if(n%i==0)
						count++;
				}
				if(count==1)
					return 1;
				else
					return 0;

		}
		console.log("enter two numbers to find twin prime numbers in between them")
		var n1=prompt("1st number: ")
		var n2=prompt("2nd number: ")
		console.log("Twin prime numbers in a given inclusive range is: ")
		for(let j=n1;j<n2-1;j++)
			if(isprime(j) && isprime(j+2))
				console.log(j," ",j+2)
        
/* 
problem:to find twin prime numbers in a given range
enter two numbers to find twin prime numbers in between them
1st number: 1
2nd number: 30
Twin prime numbers in a given inclusive range is: 
3   5
5   7 
11   13
17   19
space complexity:O(1)
time complexity:O(n^n)
*/
