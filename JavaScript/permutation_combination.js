function fact(n)
{
	if(n==0)
		return 1
	else
		return n*fact(n-1);
}

var n=prompt("enter total number of items in a sample : ")
var r=prompt("number of items to be selected from a given sample: ")
console.log("permutation(order matters) = ",fact(n)/fact(n-r))
console.log("combination(order does not matter) = ",fact(n)/(fact(n-r)*fact(r)))

/*
problem:permutation and combination finding algorithm
sample I/O:
enter total number of items in a sample :6
number of items to be selected from a given sample:2
permutation(order matters) =  30 
combination(order does not matter) =  15

space-complexity : O(n)
time-complexity : O(n)
*/
