# import operator.itemgetter
from operator import itemgetter

# define fruit list
fruit_list = []

# define flag
flag1 = True

# user input fruit and weight
while flag1:
    fruit = input("Enter a fruit type (q to quit): ")
    if fruit != 'q':
        if not len(fruit_list):
            weight = int(input("Enter the weight in kg: "))
            fruit_list.append([fruit, weight])
        else:
            weight = int(input("Enter the weight in kg: "))
            flag2 = True
            
            for i in range(0, len(fruit_list)):
                if fruit == fruit_list[i][0]:
                    fruit_list[i][1] += weight
                    flag2 = False
            if flag2:
                fruit_list.append([fruit, weight])
                
    else:
        flag1 = False

# list sort
fruit_list.sort(key=itemgetter(0))

# output
for j in range(0, len(fruit_list)):
    print(fruit_list[j][0]+', '+str(fruit_list[j][1])+'kg.')                    
