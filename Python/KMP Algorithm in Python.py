#!/usr/bin/env python
# coding: utf-8

# In[2]:


def KMPSearch(txt, pat): 
    n=len(txt)
    m=len(pat)
    lps = [0]*m 
    j = 0 
    ComputeLPSArray(pat, m, lps) 
    i = 0 
    while i < n: 
        if pat[j] == txt[i]: 
            i += 1
            j += 1
  
        if j == m: 
            print ("Found pattern at index " + str(i-j)) 
            j = lps[j-1] 
        elif i < n and pat[j] != txt[i]: 
            if j != 0: 
                j = lps[j-1] 
            else: 
                i += 1
  
def ComputeLPSArray(pat, m, lps): 
    len = 0 
    lps[0] 
    i = 1
    while i < m: 
        if pat[i]== pat[len]: 
            len += 1
            lps[i] = len
            i += 1
        else: 
            if len != 0: 
                len = lps[len-1]  
            else: 
                lps[i] = 0
                i += 1


txt = input()
pat = input()
KMPSearch(txt, pat) 
 
'''
Sample input: 
aabcababccabcb
abc
Output:
Found pattern at index 1
Found pattern at index 6
Found pattern at index 10
'''

'''
The worst case time complexity of KMP algorithm is O(n).

The space complexity of KMP algorithm is O(m), where m = length of the pattern.
'''


# In[ ]:




