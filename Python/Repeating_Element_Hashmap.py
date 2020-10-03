'''
- Finds repeating elements in a hashmap(dictionary) using a reversed dictionary.  
- Time complexity: O(1)
- Space complexity: O(1) + 8 (Please double check.)
'''


def find_repeating(intial_dict):
    reverse = {}
    for k, v in intial_dict.items():
        if v not in reverse:
            reverse[v] = [k] # populate reverse 
        else:
            reverse[v].append(k) # Append duplicate key to 
    print(reverse)

'''
# Sample input. Uncomment to test. 

initial_dict = {1: "One", 2: "Two", 3: "Three", 4: "One"}
find_repeating(initial_dict) # Output:  {'One': [1, 4], 'Two': [2], 'Three': [3]}

'''