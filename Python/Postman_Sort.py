from math import log10
from random import randint


def arraySwap(array, pos1, pos2):
    tmp = array[pos2]
    array[pos2] = array[pos1]
    array[pos1] = tmp


def getDigit(number, d_index):
    if log10(number if number > 0 else 1) < d_index:
        return None  # None if the index does not correspond to a possible index in this number
    return number % (pow(10, d_index + 1)) // pow(10, d_index)


def promptArray():
    arr = []
    rand = input("Would you like to generate a random array (y/n)? ")
    if rand == 'y':
        size = int(input("Enter the size of the array: "))
        digits = int(input("Enter the maximum number of digits: "))
        return list(map(lambda _: randint(0, pow(10, digits)-1), [0] * size))
    else:
        while True:
            _input = input("Enter a positive number or an empty value to start sorting: ")
            if _input is '':
                break
            else:
                arr.append(int(_input))
        return arr


def postmanIteration(array, digitWeight, i):
    digit_e1 = getDigit(arr[i], digitWeight)
    digit_e2 = getDigit(arr[i + 1], digitWeight)
    if digit_e2 is None and digit_e1 is not None \
            or digit_e1 is not None and (digit_e1 > digit_e2):
        arraySwap(array, i, i + 1)
        return True
    return False


def postmanSort(array):
    maxDigits = max(map(lambda x: int(log10(x if x > 0 else 1)) + 1, arr))
    for digitWeight in range(maxDigits - 1, -1, -1):
        i = 0
        while i < len(arr) - 1:
            if digitWeight == maxDigits:
                # this is the first pass
                if postmanIteration(array, digitWeight, i) and i >= 1:
                    # if we swapped some  values, check back with previous value if we have to swap more backwards
                    i -= 2
            else:
                # this is not the first pass
                prev_digit_e1 = getDigit(arr[i], digitWeight + 1)
                prev_digit_e2 = getDigit(arr[i + 1], digitWeight + 1)
                if prev_digit_e1 == prev_digit_e2:
                    #  we only compare if the previous digits are the same
                    if postmanIteration(array, digitWeight, i) and i >= 1:
                        # if we swapped some  values, check back with previous value if we have to swap more backwards
                        i -= 2

            i += 1
    return array


# Solving
arr = promptArray()
print("Array to sort is: " + str(arr))

arr = postmanSort(arr)
print("Sorted array is: " + str(arr))


# ******************************************************************************
# SAMPLE INPUT: [69, 903, 423, 196, 131, 394, 342, 27, 363, 495]
# SAMPLE OUTPUT: [27, 69, 131, 196, 342, 363, 394, 423, 495, 903]
#
# TIME COMPLEXITY : O(dn)
# SPACE COMPLEXITY : O(n + 2^d)
#
# Having n: the size of the array, d: the maximum number of digits
# ******************************************************************************
