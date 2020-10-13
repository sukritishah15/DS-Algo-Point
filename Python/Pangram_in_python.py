# Python3 code to check if the given string is a Pangram 

import string  //Using the string on your sample code
  
def ispangram(str): 
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    
    for char in alphabet: 
        if char not in str.lower(): 
            return False
  
return True
      
      
# Sample code 
string = 'the quick brown fox jumps over the lazy dog'
if(ispangram(string) == True): 
    print("Given String is a Pangram") 
else: 
    print("Given String is not Pangram") 
    
    
'''   
    Sample case 1:
    Input: 'the quick brown fox jumps over the lazy dog'
    Output: Given String is a Pangram
    
    Sample case 2:
    Input: 'hjoiztuafvk'
    Output: Given String is not a Pangram
    
    Time Complexity : O(n)
    Space Complexity : O(n)
 '''
