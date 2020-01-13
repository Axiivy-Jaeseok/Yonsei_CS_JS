# define flag
flag = True

# user input loop
while flag:
    L = int(input("Enter the limit L: "))
    sum = 0

# evaluate the sum of limit
    if L:
        for i in range(1, L+1):
            sum += (1/i)

# output
        print("Sum of the initial", L, "term(s):", format(sum, '.6f'))
    else:
        flag = False
