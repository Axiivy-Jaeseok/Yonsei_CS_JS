# Introduction of program
print('This program will convert temperatures (Fahrenheit/Celsius)')
print('Enter (F) to convert Fahrenheit to Celsius')
print('Enter (C) to convert Celsius to Fahrenheit')

# Input what user want( F or C)
which = input('Enter selection: ')

while which != 'F' and which != 'C':
    which = input("Please enter 'F' or 'C': ")

# Convert F to C
if which == 'F':
    temp = -460
    while temp < -459:
        temp = int(input('Enter temperature to convert: '))
    converted_temp = format((temp - 32) * 5/9, '.1f')
    print(temp, 'degrees Fahrenheit equals', converted_temp, 'degrees Celsius')
# Convert C to F
else:
    temp = -274
    while temp < -273:
        temp = int(input('Enter temperature to convert: '))        
    converted_temp = format((9/5 * temp) + 32, '.1f')
    print(temp, 'degrees Celsius equals', converted_temp, 'degrees Fahrenheit')
