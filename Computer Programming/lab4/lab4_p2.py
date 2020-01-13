# define num
num = 1
# print numbers field-width of 3 characters per number
while num <= 100:
    print(format(num, ">3"), end = '')
# print new-line when the program print mutiple of 10
    if num % 10 == 0:
        print("")
    num = num + 1
