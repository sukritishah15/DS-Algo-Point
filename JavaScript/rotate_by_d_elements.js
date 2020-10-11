// JavaScript code to rotate array by d elements in clockwise direction

var rotate = function (nums, k) {
    let i = 0;
    while (i < k) {
        nums.unshift(nums.pop());
        i++;
    }
    return nums;

};

const arr = [3, 4, 1, 5, 2];
const d = 2;
console.log(rotate(arr, d)); // Returns rotated element.

/*
 * Input:
 *    Array - [3, 4, 1, 5, 2]
 *    d - number of rotations of array
 * Output:
 *    Array - [5, 2, 3, 4, 1]
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
*/