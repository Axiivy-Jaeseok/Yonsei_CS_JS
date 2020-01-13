# define num, and og_num and copy the value of num to og_num
num = int(input("Enter a number: "))
og_num = num
# define dg
dg = 0
# count the digits
while num >= 10:
    num = num/10
    dg = dg+1
dg = dg+1
# when digit is 1
if dg == 1:
    print("The number "+str(og_num)+" contains 1 digit")
# when digits are bigger than 1
else:
    print("The number "+str(og_num)+" contains "+str(dg)+" digits")
