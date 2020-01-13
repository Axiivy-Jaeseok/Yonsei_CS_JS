# user input about name
name = input("Enter a first and last name: ")

# define fns(first name starts)
fns = 0
while name[fns] == ' ':
    fns += 1

# set the fne(first name ends)
fne = fns+1
while name[fne] != ' ':
    fne += 1

# set the lns(last name starts)
lns = fne+1
while name[lns] == ' ':
    lns += 1

# set the lne(last name ends)
# if last letter of name is space, find lne
# else we just print out until last letter
# output
lne = lns+1
if name[-1] == ' ':
    while name[lne] != ' ':
        lne += 1
    print(name[lns:lne]+', '+name[fns]+'.')

else:
    print(name[lns:]+', '+name[fns]+'.')




