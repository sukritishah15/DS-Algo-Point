function selection_sort(nums) { 
    let n = nums.length;
        
    for(let i = 0; i < n; i++) {
        let min_index = i;
        for(let j = i+1; j < n; j++){
            if(nums[min_index] > nums[j]) {
                min_index = j; 
            }
         }
         [nums[i], nums[min_index]] = [nums[min_index], nums[i]];
    }
}

/* 
Sample I/O:

Input:
let input = [5,6,4,7,3,8,2,9,1,10];
selection_sort(input);
console.log(input);

Output:
[
  1, 2, 3, 4,  5,
  6, 7, 8, 9, 10
]

Time Complexity: O(N^2)
Space Complexity: O(1)
Stable: no
In-Place: yes
*/
