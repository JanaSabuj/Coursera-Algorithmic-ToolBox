# python3
import numpy

# Discrete Knapsack problem without repetition
def P3(W, n, items):
    """ Finds if number of P3 having capacity W is >=3
    (int, int, list) -> (int) """
    count = 0 
    val = numpy.zeros((W+1, n+1))
    for i in range(1, W+1):
        for j in range(1, n+1):
            val[i][j] = val[if ][j-1]
            if items[j-1]<=i:
                temp = val[i-items[j-1]][j-1] + items[j-1]
                if temp > val[i][j]:
                    val[i][j] = temp
            if val[i][j] == W: count += 1

    if count < 3: print('0')
    else: print('1')

if __name__ == '__main__':
    n = int(input())
    item_weights = [int(i) for i in input().split()]
    total_weight = sum(item_weights)
    if n<3: 
        print('0')
    elif total_weight%3 != 0: 
        print('0')
    else:
        P3(total_weight//3, n, item_weights)