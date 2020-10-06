# Python problem to find majority element in an array.

def majorityElement(nums, n):
    nums.sort()
    for i in range(0, n):
        if(i+int(n/2)) < n and nums[i] == nums[i+int(n/2)]:
            return nums[i]

    return None


n = int(input("Enter the total number of elements\n"))
print('Enter a list of '+str(n) + ' number in a single line')
arr = list(map(int, input().split()))

result = majorityElement(arr, n)
if (result == None):
    print("No majority element")
else:
    print("Majority element is", result)

'''        
Time complexity ==> O(nlogn)
Space complexity=> O(1)
I/O -->
Enter the total number of elements
10
Enter a list of 10 number in a single line
1 1 3 1 2 1 1 6 5 1
O/P -->
Majority element is 1
'''
