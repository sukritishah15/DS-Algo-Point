 /*Program to find the Prix Sum Array of the given Array.
 Prefix Sum Array:
 Prefix sum array is  another array made  by sequence sum of the elements of the given array.
  */
//function to 
const prefix_sum=(arr)=>{
   //To calculate length of given array
   const n=arr.length
   //Creating new array of same size as inputs.
   const new_arr=new Array(n)
   new_arr[0]=arr[0]
   for(var i=1;i<n;i++){
      new_arr[i]=new_arr[i-1]+arr[i]
   }
   return new_arr
}
const test_array=[5,2,4,5,1]
console.log(prefix_sum(test_array))

//Sample Output:5,7,11,16,17 