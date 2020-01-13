# define list of group that include ISBN information
group = ['GS1 prefix', 'Group identifier', 'Publisher code', 'Item number', 'Check digit']
# user input about isbn code
isbn = input("Enter a ISBN: ")
# split isbn code
ISBN = isbn.split('-')
# output
for i in range(0, len(ISBN)):
    print(format(ISBN[i], '.<20'), end ='')
    print(group[i])
