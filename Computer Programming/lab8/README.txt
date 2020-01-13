(a) 11 20
    The 'n=10' for n is a global variable and 'n = n+1' for n is just local variable.
    So if we call 'foo1(n)', 'n = n + 1' calculate as a local variable and return n.
    but if we call 'foo()', it use global variable n, so y became 20.
    
(b) 2
    Although there's 'x=0' for x is global variable, there's a 'x = 1' for local variable
    in function 'foo()'. And 'bar()' is nested function for 'foo()', so it belongs to the 
    'foo()'. Therefore, 'bar()' use x for 'x=1' to calculate 'y = x+1' when we call 'foo()'.

(c) 1
    If we make 'x=1' to '# x =1', there's no local variable in 'foo()'.
    So the function 'foo()' use x for global variable 'x=0'. Even the 'bar()' is belongs to
    the 'foo()', it also use x for 'x=0' to calculate. So the result became 1.
