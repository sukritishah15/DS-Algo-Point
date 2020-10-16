using System; 
class Pangrams { 
  
    public static bool checkPangram(string str) 
    { 
        bool[] mark = new bool[26]; 
        int index = 0; 
        for (int i = 0; i < str.Length; i++) { 
            if ('A' <= str[i] && str[i] <= 'Z') 
                index = str[i] - 'A'; 

            else if ('a' <= str[i] && str[i] <= 'z') 
                index = str[i] - 'a'; 
  
            else
                continue; 
  
            mark[index] = true; 
        } 
  
        for (int i = 0; i <= 25; i++) 
            if (mark[i] == false) 
                return (false); 
  
        return (true); 
    } 
  
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
