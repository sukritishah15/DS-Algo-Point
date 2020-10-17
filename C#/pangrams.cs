using System; 
class Pangram{ 

    public static bool checkPangram(string str) 
    { 
  
        // Create a hash table to mark the 
        // characters present in the string 
        // By default all the elements of 
        // mark would be false. 
        bool[] mark = new bool[26]; 
  
        // For indexing in mark[] 
        int index = 0; 
  
        // Traverse all characters 
        for (int i = 0; i < str.Length; i++) { 
            // If uppercase character, subtract 'A' 
            // to find index. 
            if ('A' <= str[i] && str[i] <= 'Z') 
                index = str[i] - 'A'; 
  
            // If lowercase character, 
            // subtract 'a' to find 
            // index. 
            else if ('a' <= str[i] && str[i] <= 'z') 
                index = str[i] - 'a'; 
  
            // If this character is other than english 
            // lowercase and uppercase characters. 
            else
                continue; 
  
            mark[index] = true; 
        } 
  
        // Return false if any 
        // character is unmarked 
        for (int i = 0; i <= 25; i++) 
            if (mark[i] == false) 
                return (false); 
  
        // If all characters 
        // were present 
        return (true); 
    } 
  
    // Driver Code 
    public static void Main() 
    { 
        string str = "The quick brown fox jumps over the lazy dog"; 
  
        if (checkPangram(str) == true) 
            Console.WriteLine(str + " is a pangram."); 
        else
            Console.WriteLine(str + " is not a pangram."); 
    } 
} 
/*

TIME COMPLEXITY :O(N)
SPACE COMPLEXITY : O(1)

Input : Taken in the code
Output : "The quick brown fox jumps over the lazy dog" is a pangram



*/
