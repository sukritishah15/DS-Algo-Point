function countSort(array){
    return Object.entries(array.reduce((acc,val) => {
        if(!acc[val]){
            acc[val] = 0;
        }
        acc[val]++; 
        return acc;
    },{}))
    .reduce((acc, val) => {
        return acc.concat(Array.from({length:val[1]}).map(x => parseInt(val[0])));
    }, []);
}

/* Example
 * Input:
 *    Unsorted Array: Array - e.g.: [ 5,4,7,3,1,8,2,6 ]
 *
 * Output:
 *    [1,2,3,4,5,6,7,8]
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
*/
