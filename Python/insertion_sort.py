# Insertion sort in Python


def insertion_sort(arr):
    comparisons = 0
    moves = 0
    
    for step in range(1,len(arr)):
        key = arr[step]
        i = step - 1
        
        while i >= 0 and key < array[i]:
            array[i + 1] = array[i]
            i = i - 1
            comparisons += 1
            
        if array[i + 1] != key
            print(arr)
            moves += 1
    return (comparisons, moves)

data = [6,2,4,3,5,1,7]
comparisons, moves = insertion_sort(data)
print(f'Sorted Array in Ascending Order: {data}')
print(f'Sorted in {moves} moves and {comparisons} comparisons')
