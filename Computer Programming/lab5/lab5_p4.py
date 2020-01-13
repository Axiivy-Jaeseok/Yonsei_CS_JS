# user input about integer
i = int(input("Enter an integer: "))
# Define variable j
j = 0
while i>0:
# print blank and *
    print(' '*j+'*'*(2*i-1))
    i = i-1
    j = j+1
