# define list 'name'
name = []
i = 0
j = 0
# define count
count = 0
while True:
# user input name
    name.append(input("Enter a name (q to quit): "))
# program quit when user input q
    if name[i] == 'q':
        break;
    else :
# if A or a in name count increase
        count += name[i].count('a')
        count += name[i].count('A')
        i += 1
        
# output
print("Appearance of letter 'a':", count)
    
    
