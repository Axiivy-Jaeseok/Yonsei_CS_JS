# make integer list
int_list = []
# define i for while
i = 0
while True:
    int_list.append(int(input("Enter an integer: ")))
# when user input 0
    if int_list[i] == 0:
        del int_list[i]
        print(int_list)
        break;
# when user input the num greater than 100, change the num as a 'over'
    elif int_list[i] > 100:
        int_list[i] = 'over'
        i = i+1
    else:
        i = i+1
        continue
    

    
