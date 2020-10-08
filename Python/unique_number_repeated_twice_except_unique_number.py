def findUniqueNumber(n: int):
    """
    Given a set of numbers present twice except the unique number, it finds the unique number among the set of numbers.
    :param n : Size of the input
    :return : The unique integer
    """
    ans = 0
    vec = [int(x) for x in input("Enter set of numbers separated by space\n").split(' ')]
    for i in range(n):
        ans = ans ^ vec[i]
    return ans

N = int(input("Enter the number of elements\n"))
print(findUniqueNumber(N))


"""
Sample Input : 
7
1 2 3 3 2 1 4
Output : 4
Time Complexity : O(n)
Space Complexity : O(n)
"""
