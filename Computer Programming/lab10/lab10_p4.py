# define lists
input_list = []
result = []

# file input
input_file = open('data.txt', 'r')
integer = input_file.readline()

# read integer and append to list
while integer != '':
    input_list.append(int(integer[:-1]))
    integer = input_file.readline()

# make substituted at the edges
xl = [input_list[0]] + input_list + [input_list[-1]]

# result
for i in range(0, len(xl)-2):
    result.append((xl[i]+xl[i+1]+xl[i+2])/3)

print(result)
