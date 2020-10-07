//function to find gcd of two numbers 
//using euclidean algorithm

function gcd(x, y) {
    let temp;
    if (x === 0) return y;
    else if (y === 0) return x;
    else {
        while (y) {
            temp = x;
            x = y;
            y = temp % y
        }
        return x;
    }
}

console.log(gcd(num1, num2));


/*
Input -> num1 = 17, num2 = 6
Output -> 1

Input -> num1 = 4, num2 = 6
Output -> 2

---Time complexity O(logn)
---Space complexity O(1)
*/