def printArr(arr, n): 
    for i in range(n): 
        print(arr[i],end=" ") 
  
def sortArr(arr, n): 
    cnt0 = 0
    cnt1 = 0
    cnt2 = 0
    for i in range(n): 
        if arr[i] == 0: 
            cnt0+=1
          
        elif arr[i] == 1: 
            cnt1+=1
              
        elif arr[i] == 2: 
            cnt2+=1
 
    i = 0

    while (cnt0 > 0): 
        arr[i] = 0
        i+=1
        cnt0-=1
      
    while (cnt1 > 0): 
        arr[i] = 1
        i+=1
        cnt1-=1
      
    while (cnt2 > 0): 
        arr[i] = 2
        i+=1
        cnt2-=1
    print("Sorted Array is: ")
    printArr(arr, n) 
  
print("Enter the Input: ")
arr = list(map(int,input().split()))
n = len(arr)
sortArr(arr, n)

"""
Time Complexity O(N) Space Complexity O(1)
Input And Output:
Enter the Input
0 2 1 1 2 1 1 0 0 0 1
0 0 0 0 1 1 1 1 1 2 2
"""
