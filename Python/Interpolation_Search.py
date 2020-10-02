#Contributed by @Hinal-Srivastava

#Funtion to implement Interpolation Search
def Interpolation_Search(lst, n, element):
    start = 0
    end = n-1
    compare = int(start + ((end-start) / (lst[start]-lst[end])) * (element - lst[start]))
    while(start<=end and element>=lst[start] and element<=lst[end]):
        if(element == lst[compare]):
            print("Element found at ", compare+1)
        elif(element > lst[compare]):
            start = compare + 1
        elif(element < lst[compare]): 
            end = compare - 1
        else:
            print("Element Not In List")    

#Driver Program
lst = []
n = int(input("Number of elements: "))
print("Enter Elements\n", end='')
for i in range(n):
    value = int(input())
    lst.append(value)
lst.sort()
element = int(input("Enter Search element: "))
print(Interpolation_Search(lst, n, element))   

"""
*** CASE #1 ***
Sample Input
_____________

Number of elements: 4
Enter Elements
2
8
4
5
Enter Search element: 8

Output Input
_____________
Element Not In List

*** CASE #2 ***
Sample Input
_____________

Number of elements: 4
Enter Elements
2
8
4
5
Enter Search element: 1

Output Input
_____________
Element Not In List

Time Complexity: O(nlogn)
Space Complexity: O(n)
"""
