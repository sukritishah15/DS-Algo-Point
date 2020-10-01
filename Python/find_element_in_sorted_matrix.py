n, m = map(int, input("Enter the number of rows and columns: ").split())
arr = []
print("Enter the elements: ")
for i in range(n):
    temp = list(map(int, input().split()))
    arr.append(temp)

key = int(input("Enter the element that needs to be searched: "))

i = 0
j = m - 1

while i < n and j >= 0:
    curr = arr[i][j]
    if curr > key:
        j -= 1
    elif curr < key:
        i += 1
    else:
        print(f"Element {key} found!")
        break
else:
    print("Element is not present in the matrix.")

'''
Example input 1:

Enter the number of rows and columns: 3 4
Enter elements: 
12 14 17 68
13 15 18 69
16 20 25 75
Enter the element that needs to be searched: 20

Output:
Element 20 found!

Example Input 2:

Enter the number of rows and columns: 3 4
Enter elements: 
12 14 17 68
13 15 18 69
16 20 25 75
Enter the element that needs to be searched: 19

Output:
Element is not present in the matrix.

Time Complexity: O(n + m)
Space complexity: O(1)
'''
