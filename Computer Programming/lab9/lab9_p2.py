# import stack
import stack

# define RPN_stack
RPN_stack = stack.getStack()

while True:

# user input
    RPN = input("Enter an RPN expression: ")

# when user input 'q', program quits
    if RPN == 'q':
        break
    RPN_list = RPN.split()
    state = "Progress"
    i = 0
    num1 = 0
    num2 = 0
    result = 0
    equal_flag = False

# push the number to the stack
    while state == "Progress" and i < len(RPN_list):
        if RPN_list[i]=='+' or RPN_list[i]=='*' or RPN_list[i]=='-' or RPN_list[i]=='/' or RPN_list[i]=='=':
            if RPN_list[i] == '=':
                equal_flag = True
                if len(RPN_stack) == 1 and i == len(RPN_list)-1:
                    result = float(stack.pop(RPN_stack))
                else:
                    state = "Error"
            else:
                if stack.isEmpty(RPN_stack) or len(RPN_stack) == 1:
                    state = "Stack Underflow"
                    break
            
                num2 = float(stack.pop(RPN_stack))
                num1 = float(stack.pop(RPN_stack))

# evaluating the result
                if RPN_list[i] == '+':
                    stack.push(RPN_stack, format(num1+num2, '.2f'))
                elif RPN_list[i] == '*':
                    stack.push(RPN_stack, format(num1*num2, '.2f'))
                elif RPN_list[i] == '/':
                    stack.push(RPN_stack, format(num1/num2, '.2f'))
                elif RPN_list[i] == '-':
                    stack.push(RPN_stack, format(num1-num2, '.2f'))
            
        else:
            stack.push(RPN_stack, RPN_list[i])

        i = i+1

    if len(RPN_stack) >= 1:
        state == "Error"

# output
    if state == "Progress" and equal_flag == True:
        if float.is_integer(result):
            print("Value of the expression :", int(result))
        else:
            print("Value of the expression :", format(result, '.2f'))

    else:
        print("Evaluation error")
        break

    RPN_stack = []
