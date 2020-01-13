# define the fuction evalPolynomial
def evalPolynomial(x):
# evaluate the result for polynomial
    result = 3*(x**5)+2*(x**4)-5*(x**3)-x**2+7*x-6
    return result

# user input
num = int(input("Enter a value for x: "))
pol = evalPolynomial(num)

# print output
print("Polynomial for x="+str(num)+": "+str(pol))
