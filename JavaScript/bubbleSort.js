function bubbleSort(arr){
    for(j=0;j<arr.length-1;j++){
      for(i=0;i<arr.length-1;i++){ 
        if(arr[i]>arr[i+1])
            [arr[i],arr[i+1]] = [arr[i+1],arr[i]]
    }
  }
    return arr;
}

console.log(bubbleSort([5,4,7,3,1,8,2,6])); // [1,2,3,4,5,6,7,8]


/* Example
 * Input:
 *    Unsorted Array: Array - e.g.: [ 5,4,7,3,1,8,2,6 ]
 * 
 * Output:
 *    Sorted Array: [1,2,3,4,5,6,7,8]
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
*/