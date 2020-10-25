def TowerOfHanoi(n , first, last, mid): 
    if n == 1: 
        print ("Move disk 1 from rod",first,"to rod",last) 
        return
    TowerOfHanoi(n-1, first, mid, last) 
    print ("Move disk",n,"from rod",first,"to rod",last )
    TowerOfHanoi(n-1, mid, last, first) 

n=int(input())
TowerOfHanoi(n, 'F', 'M', 'L')   # First Rod-> F, Middle rod -> M, Last Rod -> L

"""
Complexity of the code

-Time Complexity - O(2^n)
-Space Complexity - O(2^n)

"""