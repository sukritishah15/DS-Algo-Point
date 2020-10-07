using System;   
class Tim 
{   public const int RUN = 32;       
    public static void insertionSort(int[] lst, int left, int right)  
    {  
        for (int i = left + 1; i <= right; i++)  
        {  
            int temp = lst[i];  
            int j = i - 1;  
            while (j >= left && lst[j] > temp)  
            {  
                lst[j+1] = lst[j];  
                j--;  
            }  
            lst[j+1] = temp;  
        }  
    }        
    public static void merge(int[] lst, int l, int m, int r)  
    {  
        int len1 = m - l + 1, len2 = r - m;  
        int[] left = new int[len1]; 
        int[] right = new int[len2];  
        for (int x = 0; x < len1; x++) 
            left[x] = lst[l + x];  
        for (int x = 0; x < len2; x++)  
            right[x] = lst[m + 1 + x];  
        int i = 0;  
        int j = 0;  
        int k = l;          
        while (i < len1 && j < len2)  
        {  
            if (left[i] <= right[j])  
            {  
                lst[k] = left[i];  
                i++;  
            }  
            else
            {  
                lst[k] = right[j];  
                j++;  
            }  
            k++;  
        }            
        while (i < len1)  
        {  
            lst[k] = left[i];  
            k++;  
            i++;  
        }          
        while (j < len2)  
        {  
            lst[k] = right[j];  
            k++;  
            j++;  
        }  
    }  
    public static void timSort(int[] lst, int n)  
    {  
        
        for (int i = 0; i < n; i+=RUN)  
            insertionSort(lst, i, Math.Min((i+31), (n-1)));   
        for (int size = RUN; size < n; size = 2*size)  
        {  
            for (int left = 0; left < n; left += 2*size)  
            {  
                int mid = left + size - 1;  
                int right = Math.Min((left + 2*size - 1), (n-1));  
                merge(lst, left, mid, right);  
            }  
        }  
    }  

    public static void printArray(int[] lst, int n)  
    {  
        for (int i = 0; i < n; i++)  
            Console.Write(lst[i] + " ");  
        Console.Write("\n");  
    }

    public static void Main() 
    { 
        int[] lst = {5, 21, 7, 23, 19};  //sample input
        int n = lst.Length; 
        Console.Write("Given Array is\n");  
        printArray(lst, n);  
        
        timSort(lst, n);  
        
        Console.Write("After Sorting Array is\n");  
        printArray(lst, n);  // sample output: 5 7 19 21 23
    } 
      
    //This code is contributed by tanishq67
} 
//space complexity O(n);
//Time complexity O(nlog(n));
