<?php
/*
The Fibonacci numbers are the numbers in the following integer sequence.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..

Given the value of n, find the sum of the series.
*/

$n= intval(readline("Enter the value of n:"));
$fn1 = 1;
$fn2 = 0;
$sum=0;
for($i = 0; $i < $n+1; $i++){
  $sum=$fn1+$fn2;
  $t=$fn2 + $fn1;
  $fn2 =$fn1;
  $fn1 = $t;
}
echo strval($sum-1)."\n";
/*
Example:
Input: 9
Output: 88
Time complexity: O(n)
Space complexiity: O(1)
*/

?>