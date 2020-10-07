//Kadane's algorithm

function kadaneAlgo(arr){
    max=Number.NEGATIVE_INFINITY, sum=0,left=0,right=0;
    for(i=0;i<arr.length;i++){
            sum += arr[i];
            if(max<sum){
                max = sum;
                right = i;
            }

            if(sum<0){
                sum=0;
                left=i+1;
            }
        }
        console.log(max);
        return arr.slice(left,right+1);
}

console.log(kadaneAlgo([-2,-3,4,-1,-2,1,5,-3]));

/*
    Name of Algorithm : Kadane's Algorithm
    Time Complexity : O(n)
    Space Complexity : O(1)
    User is required to give array as an input.
    Maximum contiguous sum of the subarray will be printed.
    And the sub-array will be returned.
    Input :
    -2 -3 4 -1 -2 1 5 -3
    Output :
    7
    Explanation :
    4 + (-1) + (-2) + 1+ 5 = 7
    returns [4,-1,-2,1,5]
*/
