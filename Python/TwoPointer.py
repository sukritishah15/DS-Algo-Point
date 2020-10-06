# Two Pointer Algorithm is an effective technique which is used for searching pairs in a sorted array.
# This technique can be used to solve a number of problems, however the following code demonstrates how to use it to solve the following question:


# Question: You are given an array consisting of n integers a1, a2, ..., an. Initially ax=1, all other elements are equal to 0.
# You have to perform m operations. During the i-th operation, you choose two indices c and d such that li≤c,d≤ri, and swap ac and ad.
# Calculate the number of indices k such that it is possible to choose the operations so that ak=1 in the end.

def intersect(s1, s2):
    return s2[0] <= s1[0] <= s2[1] or s2[0] <= s1[1] <= s2[1]
 
def solve():
    n, x, m = map(int, input().split())
    l = x
    r = x
    for i in range(m):
        tl, tr = map(int, input().split())
        if intersect((l, r), (tl, tr)):
            l = min(l, tl)
            r = max(r, tr)
    print(r - l + 1)
 
t = int(input())
while t:
    t -= 1
    solve()

'''
Sample input  
3
6 4 3
1 6
2 3
5 5
4 1 2
2 4
1 2
3 3 2
2 3
1 2

Sample output 
6
2
3



Time complexity O(n)
Space complexity O(1)


Other Problems that can be solved using Two Pointer Technique are:
1. 3 Sum Problem
2. Intersection of Sorted Arrays
3. Remove Duplicates from Array
4. Container with most Water

'''
