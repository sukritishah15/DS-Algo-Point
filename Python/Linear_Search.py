# Linear search => An easy to go searching algorithm that used to search element effeciently in a smaller set of values
def linear(arr,n,x):
    for i in range(n):
        if(arr[i] == x):
            return i
    return -1

print('Enter a list of '+str(n) + ' number in a single line')
arr =list(map(int,input().split()))
x = int(input("Enter which element you want to find\n"))
n = len(arr)
result = linear(arr,n,x)
if (result == -1):
        print("Element not found")
else:
        print("Element found at" ,result+1,"position")

'''        
Time complexity ==> O(n)
Space complexity=> O(1)
I/O -->
Enter a list of 10 number in a single line
1 2 3 4 5 6 7 8 9 10
Enter which element you want to find
5
Element found at 5 position
'''  



    

    


    
