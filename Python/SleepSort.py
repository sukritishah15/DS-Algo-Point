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