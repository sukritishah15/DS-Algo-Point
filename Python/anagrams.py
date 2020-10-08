print('Insert first string')
string1 = input()
print('Insert second string')
string2 = input()

print(string1 + ' - ' + string2 + ' are anagrams?', sorted(string1) == sorted(string2))

'''
Check whether the strings in input are anagrams or not.

Two strings, a and b, are called anagrams if they contain all the same characters in the same frequencies. 
For example, the anagrams of CAT are CAT, ACT, TAC, TCA, ATC, and CTA.

Sample Input:
string1=CAT
string2=ACT

Sample Output:
true

Time complexity : O(N log N)
Space complexity: O(1)
'''
