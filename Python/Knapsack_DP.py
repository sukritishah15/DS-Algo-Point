def knapsack(W: int, weights: list, values: list):
    n = len(weights)

    K = [[0 for _ in range(n+1)] for _ in range(W+1)]

    for i in range(1, n+1):
        for j in range(1, W+1):
            K[j][i] = K[j][i-1]

            w = weights[i-1]
            v = values[i-1]

            if w <= j:
                K[j][i] = max(K[j][i], K[j - w][i-1] + v)

    return K[W][n]


if __name__ == "__main__":
    W = int(input("Capacity: "))
    weights = list(map(int, input("Weights: ").split()))
    values = list(map(int, input("Values: ").split()))

    profit = knapsack(W, weights, values)
    print("\nProfit:", profit)

'''
Time complexity  -> O(n*W)
Space complexity -> O(n*W)
n -> number of weights
W -> capacity

Sample input
Capacity: 50
Weights: 10 20 30
Values: 60 100 120

Sample output
Profit: 220
'''
