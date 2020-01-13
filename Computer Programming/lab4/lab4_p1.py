#define sum, num
sum = 0
num = 1
#User input until num isn't 0 and sum the result(Do not sum when num > 100)
while num != 0:
    num = int(input("Your number: "))
    if num <= 100:
        sum = sum + num
#print the result
print("Sum:", sum)
