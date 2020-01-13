# import stack module
import stack

# user input
pa = input("Enter parentheses and/or braces: ")

# define pa_stack
pa_stack = stack.getStack()

for i in range(0, len(pa)):

# when character is left parentheses or braces push to the stack
    if pa[i] == "(" or pa[i] == "{":
        stack.push(pa_stack, pa[i])

# when character is right parentheses or braces pop the stack
# if the value of the stack for top is left parentheses or braces
    else:
        if stack.top(pa_stack) == "(" and pa[i] == ")":
            stack.pop(pa_stack)
        elif stack.top(pa_stack) == "{" and pa[i] == "}":
            stack.pop(pa_stack)

# output "Nested properly." when stack is empty
if stack.isEmpty(pa_stack):
    print("Nested properly.")
else:
    print("Not properly nested.")
