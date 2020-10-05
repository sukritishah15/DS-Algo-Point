'''
Input and output format:
>>Enter the coordinates of the first point:
10 20
>>Enter the coordinates of the second point:
20 30
>>Manhattan Distance between the two points is : 20
Time complexity: O(1) 
Space complexity: O(1) 
'''


x1 , x2 = list(map(int,input("Enter the coordinates of the first point:").strip().split())) 
y1 , y2 = list(map(int,input("Enter the coordinates of the first point:").strip().split())) 
manhattanDistance = abs(x1 - x2) + abs(y1 - y2)

print("Manhattan Distance between the two points is :" + str(manhattanDistance)) 