using System; 
  
class Main { 
    // Fills prefix sum array 
    static void fillPrefixSum(int[] arr, int n, 
                              int[] prefixSum) 
    { 
        prefixSum[0] = arr[0]; 
  
        // Adding present element 
        // with previous element 
        for (int i = 1; i < n; ++i) 
            prefixSum[i] = prefixSum[i - 1] + arr[i]; 
    } 
  
    // Driver code 
    public static void Main() 
    { 
        int[] arr = { 10, 4, 16, 20 }; 
        int n = arr.Length; 
        int[] prefixSum = new int[n]; 
  
        fillPrefixSum(arr, n, prefixSum); 
  
        for (int i = 0; i < n; i++) 
            Console.Write(prefixSum[i] + " "); 
        Console.Write(""); 
    } 
} 
/*
        Input :Taken on the code
        Output :10 14 30 50
        Time Complexity: O(n)
        Space Complexity: O(n)

*/
