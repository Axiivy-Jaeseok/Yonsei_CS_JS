Question 1 :
    sol) As the n defines that n = (n+1)%100, 
	The highest value that will be assigned to n is 99
	Because if it is bigger than 99, it could be calculate by mod100
	ex) if 101 % 100 = 1 
    ans) 99


Question 2:
    (a) var1 * 8 - var2 + 32 / var3
    sol) operator '*' and '/' precedence is higher than '+' and '-'.
    ans) (((var1 * 8) - var2) + (32 / var3))

    (b) var1 - 6 ** 4 * var2 ** 3
    sol) ** is the highest. And * is higher than -.
    ans) (var1 - ((6 ** 4) * (var2 ** 3)))


Question 3:
    (a) var1*var2 -> (var1*var2)*var3 -> ((var1*var2)*var3) - var4
	left to right.
    (b) var1*var2 -> (var1*var2)/var3
	left to right.
    (c) var2**var3 -> var1**(var2**var3)
	right to left.
