//Linear Search

function linear_search(arr,k){
    for(i=0;i<arr.length;i++){
        if(k==arr[i])
        {
            return i+1;
        }
    }
    return -1;
}

//Example
console.log(linear_search([3,4,5,6,7,2,9,0],6)); // 4

/* Linear Search
Input : Array and key to be searched 
Output : Returns position of first key present in array
          Returns -1 if key not present in array
Time Complexity: O(n)
Space Complexity: O(1)
*/