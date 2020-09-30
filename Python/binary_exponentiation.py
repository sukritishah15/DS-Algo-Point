#To compute a ^ b, this code runs in O(log b) instead of O(b)

def BinaryExpo(a, b):
    if b == 0:
        return(1)
    res = BinaryExpo(a, b // 2)
    if b % 2 == 1:
        return(res * res * a)
    else:
        return(res * res)

#driver code
a, b = [int(x) for x in input().split()]
print(BinaryExpo(a, b))

#input: 2 3
#output: 8
