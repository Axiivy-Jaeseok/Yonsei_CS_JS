# define function modCount
def modCount(n,m):
# define count for count how many num for given condition
    count = 0
# find how many integers from 1 to n that divisible by m
    for i in range(1, n+1):
        if i % m == 0:
            count = count+1
    return count
