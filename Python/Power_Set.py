def Powerset(setx):
    
    #returns and displays Algorithms.powerset of a set

    number_of_set=2**len(setx)
    list_of_subsets=[]

    for i in range(number_of_set):
        subset=[]
        
        for j in range(len(setx)):
            if i & (1<<j):
                subset.append(setx[j])
        
        list_of_subsets.append(subset)

    print("Power Set:",list_of_subsets)   
    return list_of_subsets


setx=list(str(input("Enter set values: ")))
pset=Powerset(setx)

"""
Problem: 
Given a set of values, we need to find the power set i.e. collection of all possible subsets/combinations.

For Example-
Enter set values: abc
Power Set: [[], ['a'], ['b'], ['a', 'b'], ['c'], ['a', 'c'], ['b', 'c'], ['a', 'b', 'c']]

Enter set values: 12
Power Set: [[], ['1'], ['2'], ['1', '2']]

Enter set values: NO1
Power Set: [[], ['N'], ['O'], ['N', 'O'], ['1'], ['N', '1'], ['O', '1'], ['N', 'O', '1']]

n = length of expression
Time Complexity :- O(n*2^n)
Space Complexity :- O(n*2^n)

"""