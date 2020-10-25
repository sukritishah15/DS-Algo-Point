function sleepSort(array) {
    array.forEach(e => {
            setTimeout( () => {console.log(e)},e);
    });
}

/* Example
 * Input:
 *    Unsorted Array: Array - e.g.: [ 5,4,7,3,1,8,2,6 ]
 *
 * Output:
 *    1,2,3,4,5,6,7,8
 *
 * Time Complexity: O(max(input))
 * Space Complexity: O(1)
*/
