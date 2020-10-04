const binarySearch = (sortedArray, seekElement) => {
  let startIndex = 0;
  let endIndex = sortedArray.length - 1;

  while (startIndex <= endIndex) {
    const middleIndex = startIndex + Math.floor((endIndex - startIndex) / 2);
    if (sortedArray[middleIndex] === seekElement) {
      return middleIndex;
    }
    if (sortedArray[middleIndex] < seekElement) {
      startIndex = middleIndex + 1;
    } else {
      endIndex = middleIndex - 1;
    }
  }

  return -1;
};

const sortedArray = [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ];
const firstSeekElement = 8;
const secondSeekElement = 21;
console.log(binarySearch(sortedArray, firstSeekElement)); // Returns 7, index of seekElement;
console.log(binarySearch(sortedArray, secondSeekElement)); // Returns -1 because secondSeekElement was not found in the given array.

/*
 * Input:
 *    sortedArray: Array - Sorted array, e.g.: [ 1, 2, 3, 4, 5 ]
 *    seekElement: Any - Element that we are searching for in sortedArray.
 * Output:
 *    Number - The index of the searched element or -1 if the element was not found.
 *
 * Time Complexity: O(log(n))
 * Space Complexity: O(1)
*/
