# Python 3 program to find minimum number of denominations 
  
def findMin(V): 
      
    # All denominations of Indian Currency 
    deno = [1, 2, 5, 10, 20, 50,  
            100, 500, 1000] 
    n = len(deno) 
      
    # Initialize Result 
    ans = [] 
  
    # Traverse through all denomination 
    i = n - 1
    while(i >= 0): 
          
        # Find denominations 
        while (V >= deno[i]): 
            V -= deno[i] 
            ans.append(deno[i]) 
  
        i -= 1
  
    # Print result 
    for i in range(len(ans)): 
        print(ans[i], end = " ") 
  
# Driver Code 
if __name__ == '__main__': 
    n = 93
    print("Following is minimal number", 
          "of change for", n, ": ", end = "") 
    findMin(n)
    
    
"""

Output:
Following is minimal number of change 
for 93: 50  20  20  2  1
Complexity Analysis:
Time Complexity: O(V).
Auxiliary Space: O(1) as no additional space is used.

"""    
    
