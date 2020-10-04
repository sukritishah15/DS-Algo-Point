
def print_fizz_buzz(start_point, end_point):

    for i in range(start_point, end_point+1):

        # if number is divisible by 15 print FizzBuzz
        if i % 15 == 0:
            print("FizzBuzz")
        # if number is divisible by 3 print Fizz
        elif i % 3 == 0:
            print("Fizz")
        # if number is divisible by 5 print Buzz
        elif i % 5 == 0:
            print("Buzz")
        # else print the number
        else:
            print(i)

start_point = 1
end_point = 100

print_fizz_buzz(start_point, end_point)

"""
Function print_fizz_buzz:

Input: 2 integers, start point and end point

Output: prints the words Fizz, Buzz, FizzBuzz or integer itself 
for each number between start and end point (inclusive) 

Time complexity: O(N) (N is length of range of numbers)

Space complexity: O(1) (Uses only constant memory for iterator from start to end)
"""
