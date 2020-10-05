var n = prompt("enter the size of an array required : ");
n = parseInt(n);
var arr = new Array();
//taking input for array
for (let i = 0; i < n; i++) {
	arr[i] = prompt("element " + (i + 1) + ":");
	arr[i] = parseInt(arr[i]);
}

//to find mean of a given array
var sum = 0;
for (let i = 0; i < n; i++) {
	sum = sum + arr[i]
}
console.log("Mean of a given array is : ", sum / n);
//to find median of a given array

//sort the given array
arr1 = arr.sort();
var half = Math.floor(arr1.length / 2);
if (n % 2 == 0) {
	console.log("Median of a given array is : ", (arr1[half] + arr1[half - 1]) / 2.0);
} else
	console.log("Median of a given array is : ", arr1[half]);
  
  
  /*
  problem: to find mean and median of a given array
  sample I/O:
  enter the size of an array required : 7
  element 1:10
  element 2:23
  element 3:2
  element 4:21
  element 5:23
  element 6:38
  element 7:38
  Mean of a given array is : 22.142857142857
  Meadian of a given array is : 23
  
  space complexity: O(log(n))
  time complexity: O(nlog(n))
  */
