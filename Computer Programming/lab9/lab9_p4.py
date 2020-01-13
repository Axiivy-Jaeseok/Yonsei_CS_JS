import turtle
import math

def drawFlower(myturtle, r):
    """Draws a flower composed of 24 circles
       on the screen. The radius of the
       circles is ''r''.
       The drawing color is ''red''.
       The turtle ''myturtle'' is already
       positioned in the center of the circle.
    """

# set the pencolor as red
    myturtle.pencolor('red')

# draw the 24 circles
    for i in range(0, 361, int(360/24)):
        myturtle.penup()
        myturtle.setposition(r*math.cos(math.radians(i)), r*math.sin(math.radians(i)))
        myturtle.pendown()
        for j in range(0, 361):
            if j == 0:
                myturtle.penup()
                myturtle.setposition(r*math.cos(math.radians(i))-r*math.cos(math.radians(j)), r*math.sin(math.radians(i))-r*math.sin(math.radians(j)))
                myturtle.pendown()
            else:
                myturtle.setposition(r*math.cos(math.radians(i))-r*math.cos(math.radians(j)), r*math.sin(math.radians(i))-r*math.sin(math.radians(j)))
