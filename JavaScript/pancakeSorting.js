findMaxIndex = (arr, k) => {
  let max = -Infinity;
  let maxIndex = 0;
  for(let i = 0; i < k; i+=1){
    if(arr[i] >= max){
      max = arr[i];
      maxIndex = i
    }
  }
  return maxIndex;
};

flip = (arr, k) => {
  let i = 0;
  while (i < k) {
    let temp = arr[k];
    arr[k] = arr[i];
    arr[i] = temp;
    i+=1;
    k-=1;
  }
  return arr;
};

pancakeSort = (arr) => {
  let i = arr.length;
  while(i > 1){
    let maxIndex = findMaxIndex(arr, i);
    if(maxIndex !== i - 1) {
      flip(arr, maxIndex);
      flip(arr, i - 1);
    }
    i-=1;
  }
  return arr;
};

const unsortedArray = [3, 4, 1, 5, 2];
console.log(pancakeSort(unsortedArray));

/*
 * Input: Array, e.g.: [3, 4, 1, 5, 2]
 * Output: Array, e.g.: [ 1, 2, 3, 4, 5 ]
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
*/
