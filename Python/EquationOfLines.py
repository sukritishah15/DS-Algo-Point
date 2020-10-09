# Program to find the distance, slope, and equation of a line between 2 points (X1,Y1) and (X2,Y2)

import math

def lineAnalysis(x1, y1, x2, y2):
    slope = (y2 - y1) / (x2 - x1)
    distance = math.sqrt((x2-x1)**2 + (y2-y1)**2)
    print("The slope of the line is", slope)
    print("The distance between the two points is", distance)
    print("The equation of the line between the two points is " + str(y1), "+ " + str(slope) + "(x-" + str(x1) + ")")


def main():
    lineAnalysis(3, 4, 6, 7)

main()

# Sample I/O
# Input: 3, 4, 6, 7
# Output:
    # The slope of the line is 1.0
    # The distance between the two points is 4.242640687119285
    # The equation of the line between the two points is 4 + 1.0(x-3)

# Time Complexity = O(1)
# Space Complexity = O(1)