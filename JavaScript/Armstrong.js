function isArmstong(n) {
    let sum = 0;
    let numberOfDigits = n.toString().length;

    let temp = n;
    while (temp > 0) {
        let remainder = temp % 10;
        sum += remainder ** numberOfDigits;
        temp = parseInt(temp / 10);
    }
    if (sum == n) {
        console.log(`${n} is an Armstrong number.`);
        return true;
    }
    else {
        console.log(`${n} is not an Armstrong number.`);
        return false;
    }
}

isArmstong(85);
isArmstong(407);

/*
Problem: To Check whether a given number is
an Armstrong number or not.

--------------------------------

INPUT:
1st number: 85
2nd number: 407

OUTPUT:
85 is not an Armstrong number.
407 is an Armstrong number.

--------------------------------

Complexity:

Worst case time complexity: O(log(n))
Average case time complexity: O(log(n))
Best case time complexity: O(log(n))
Space complexity: O(1)

*/