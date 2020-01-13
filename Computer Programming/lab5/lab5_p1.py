# set lar_num
lar_num = float(input("Enter a number: "))
# set flag as True
flag = True
# if user input negative or 0 as a first num, print this para
if lar_num <= 0:
    print("No positive number was entered")
# finding largest num
else:
    while flag:
        new_num = float(input("Enter a number: "))
        if new_num <= 0:
            flag = False
        if new_num>lar_num:
            lar_num = new_num
# print output
    print("The largest number entered was", format(lar_num, ".2f"))
