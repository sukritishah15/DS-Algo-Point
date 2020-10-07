//Program to swap Two numbers without using a third variable

let num1 = 50
let num2 = 10
console.log(`num1 before swap : ${num1}`, `, num2 before swap : ${num2}`);
console.log();

num1 = num1 + num2;
num2 = num1 - num2;
num1 = num1 - num2;

console.log(`num1 after swap : ${num1}`, `, num2 after swap : ${num2}`);
console.log();


/*

Sample case 1 :
  Input => num1 (say 10), num2 (say 20)

  Output =>   num1 before swap : 10, num2 before swap : 20
              num1 after swap : 20,  num2 after swap : 10


Sample case 2 :
  Input => num1 (say -50), num2 (say 10)

  Output =>   num1 before swap : -50, num2 before swap : 10
              num1 after swap : 10,  num2 after swap : -50



  space complexity: O(1)
  time complexity: O(1)
*/