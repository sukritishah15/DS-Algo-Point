const arr = [10, 5, 6, 12, 7, 1];
const sumRecursively = (arr, start = 0, res = 0) => {
   if(start < arr.length){
      return sumRecursively(arr, start+1, res+arr[start]);
   };
   return res;
};
const partSumRecursively = (arr, partSum = [], start = 0, end =
arr.length-1) => {
   if(start <= end){
      return partSumRecursively(arr, partSum.concat(sumRecursively(arr,
      start)), ++start, end);
   };
   return partSum;
};
console.log(partSumRecursively(arr));