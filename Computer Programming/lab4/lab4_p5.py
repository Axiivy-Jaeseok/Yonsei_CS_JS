# input income
income = int(input("Enter the taxable income in USD: "))
# compare the income with if and elif and evaluate the tax
if income <= 750:
    tax = income*0.01
elif income > 750 and income < 2250:
    tax = (income-750)*0.02+7.50
elif income > 2250 and income < 3750:
    tax = (income-2250)*0.03+37.50
elif income > 3750 and income < 5250:
    tax = (income-3750)*0.04+82.50
elif income > 5250 and income < 7000:
    tax = (income-5250)*0.05+142.50
elif income > 7000:
    tax = (income-7000)*0.06+230.00
# print tax
print("Tax due:", format(tax, ".2f"), "USD")
