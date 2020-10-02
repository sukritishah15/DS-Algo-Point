#Contributed by @Hinal-Srivastava

#Funtion to implement Interpolation Search
def Interpolation_Search(lst, n, element):
    start = 0
    end = n-1
    compare = int(start + ((end-start) / (lst[start]-lst[end])) * (element - lst[start]))
    while(start<=end and element>=lst[start] and element<=lst[end]):
        if(element == lst[compare]):
            print("Element found at ", i)
        elif(element > lst[compare]):
            start = compare + 1
        elif(element < lst[compare]): 
            end = compare - 1
        else:
            print("Element Not In List")    

#Driver Program
lst = []
n = int(input("Number of elements: "))
print("Enter Elements", end='')
for i in range(n):
    value = int(input())
    lst.append(value)
lst.sort()
element = int(input("Enter Search element: "))
print(Interpolation_Search(lst, n, element))    
