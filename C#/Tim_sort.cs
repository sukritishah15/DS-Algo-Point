using System;  
   
class GFG  
{  
    public const int RUN = 32; 
      
    public static void insertionSort(int[] arr, int left, int right)  
    {  
        for (int i = left + 1; i <= right; i++)  
        {  
            int temp = arr[i];  
            int j = i - 1;  
            while (j >= left && arr[j] > temp)  
            {  
                arr[j+1] = arr[j];  
                j--;  
            }  
            arr[j+1] = temp;  
        }  
    }  
        
      
    public static void merge(int[] arr, int l, int m, int r)  
    {  

        int len1 = m - l + 1, len2 = r - m;  
        int[] left = new int[len1]; 
        int[] right = new int[len2];  
        for (int x = 0; x < len1; x++) 
            left[x] = arr[l + x];  
        for (int x = 0; x < len2; x++)  
            right[x] = arr[m + 1 + x];  
        
        int i = 0;  
        int j = 0;  
        int k = l;  
        
        
        while (i < len1 && j < len2)  
        {  
            if (left[i] <= right[j])  
            {  
                arr[k] = left[i];  
                i++;  
            }  
            else
            {  
                arr[k] = right[j];  
                j++;  
            }  
            k++;  
        }  
        
          
        while (i < len1)  
        {  
            arr[k] = left[i];  
            k++;  
            i++;  
        }  
        
        
        while (j < len2)  
        {  
            arr[k] = right[j];  
            k++;  
            j++;  
        }  
    }  
        
  
    public static void timSort(int[] arr, int n)  
    {  
        
        for (int i = 0; i < n; i+=RUN)  
            insertionSort(arr, i, Math.Min((i+31), (n-1)));   
        for (int size = RUN; size < n; size = 2*size)  
        {  
 
            for (int left = 0; left < n; left += 2*size)  
            {  
              
                int mid = left + size - 1;  
                int right = Math.Min((left + 2*size - 1), (n-1));  
      
                merge(arr, left, mid, right);  
            }  
        }  
    }  

    public static void printArray(int[] arr, int n)  
    {  
        for (int i = 0; i < n; i++)  
            Console.Write(arr[i] + " ");  
        Console.Write("\n");  
    }  
      
    public static void Main() 
    { 
        int[] arr = {5, 21, 7, 23, 19};  
        int n = arr.Length; 
        Console.Write("Given Array is\n");  
        printArray(arr, n);  
        
        timSort(arr, n);  
        
        Console.Write("After Sorting Array is\n");  
        printArray(arr, n);  
    } 
      
    //This code is contributed by tanishq67
} 