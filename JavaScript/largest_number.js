let num=prompt("enter a number : ")
var arr=[]
var n=0;
//an array to store number's digits
for(let i=num;i!=0;i=parseInt(i/10))
{
	arr.push(parseInt(i%10))
}
//sort array in ascending order
arr.sort()
//now form a largest number from a given sorted array
for(let i=arr.length-1;i>=0;i--)
{
	n=n+(arr[i]*Math.pow(10,i))
}
console.log("A largest number formed from a given number is: ",n)

/*
problem- to form largest number from a given number
sample I/O:
enter a number : 3781035
A largest number formed from a given number is: 8753310

space complexity: O(log(n))
time complexity: O(nlog(n))
*/
