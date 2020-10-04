function fibonacciNumber(n){
  let num1 = 0;
  let num2 = 1;
  for(var i = 2; i < n; i++){
    num2 = num2 + num1;
    num1 = num2 - num1;
  }
  return num2;
}

function fibonacciSum(n){
  return fibonacciNumber(n + 2) - 1;
}

/*
Example:
Input: 11
Output: 143

Time complexity: n
Space complexiity: 2

*/
