#Python Program to Sort a List using Counting Sort Algorithm

def counting_sort(ar):
    m = int(max(ar)) + 1
    count = [0] * m   #Count List, it is initialised to a list of size one more than the largest list item

    #This for loop computes the frequency of each list item and stores it in the count list
    for a in ar:
        count[a] += 1

    i = 0


    for a in range(m):
        for c in range(count[a]):
            ar[i] = a
            i += 1

    return ar

l = []
n = int(input("Enter number of elements: "))

for i in range(0, n):
    e = int(input())

    l.append(e)

print("Initial List:",l)
print("Sorted List:",counting_sort(l))


'''
Sample input:
Enter number of elements: 5
1
5
8
1
4

Sample Output:
Initial List: [1,5,8,1,4]
Sorted List: [1,1,4,5,8]

Time Complexity is:O(n+max)
Space Complexity is:O(n+max)
                    where max: largest number in the input list
                    and n: size of input list

'''
