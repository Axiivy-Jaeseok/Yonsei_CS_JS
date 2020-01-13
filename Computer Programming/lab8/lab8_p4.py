# import turtle
import turtle
# set the screen
turtle.setup(800, 600)
windows = turtle.Screen()
x_turtle = turtle.getturtle()
x_turtle.hideturtle()
x_turtle.penup()
# drawing left-top to right-bottom
x_turtle.setposition(-400,300)
x_turtle.pendown()
x_turtle.setposition(400,-300)
x_turtle.penup()
# drawing right-top to left-bottom
x_turtle.setposition(400,300)
x_turtle.pendown()
x_turtle.setposition(-400,-300)

windows.exitonclick()
