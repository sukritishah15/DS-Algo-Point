import threading
from time import sleep

def printSleepSort(i):
    sleep(i) #Sleeps for i seconds
    print(i) #Prints the value of i

n = int(input("Enter the size of the array\n"))
items = []

print("Enter individual array elements in a new line.")
for i in range(n):
    items.append(int(input()))

print("Printing the sorted array - ")
for item in items:
    th = threading.Thread(target=printSleepSort, args = (item,))
    th.start()
    
    
"""
Sample Input - 8, 9, 3, 1, 7
Sample Output - 1, 3, 7, 8, 9

Time Complexity - 
Since all the threads start at once, the maximum time taken by the algorithm will be the maximum element in the input array.
Therefor the time complexity is - O(max(input))
"""
