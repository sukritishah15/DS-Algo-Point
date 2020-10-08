def GreatestCommonDivisor(a,b): 
    if(b==0): 
        return a 
    else: 
        return GreatestCommonDivisor(b,a%b) 

a,b = input().split()

print (GreatestCommonDivisor(a,b))

# sample input 30 24 
# sample output 6
# time complexity O(log(a.b))
# space complexity O(log(a.b))
