import turtle

def drawSquare(myturtle, x, y, a):
    """ This function is drawing square with turtle

        User input the value for lower-left corner's pixel of square.
        a is the value of length of square's one side.
        It draws square with the pixels of x, y, a.
    """
# move to (x,y) with penup not to draw line 
    myturtle.penup()
    myturtle.setposition(x,y)
    myturtle.pendown()
# draw square with setposition
    myturtle.setposition(x+a,y)
    myturtle.setposition(x+a,y+a)
    myturtle.setposition(x,y+a)
    myturtle.setposition(x,y)
