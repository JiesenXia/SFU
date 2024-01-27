### Author: Tao Tao   Date: Oct 24
import turtle as t
import random as r


#define functions


def square():
    t.pendown()
    for i in range(4):
        t.forward(100)
        t.right(90)
    t.penup()
    return
	
	
def rectangle():
    t.pendown()
    for i in range(2):
        t.forward(100)
        t.right(90)
        t.forward(50)
        t.right(90)
    t.penup()
    return
	
		
def triangle():
    t.pendown()
    for i in range(3):
        t.forward(100)
        t.right(120)
    t.penup()
    return		
	
		
				
def p_square(s):
    t.pendown()
    for i in range(4):
        t.forward(s)
        t.right(90)
    t.penup()
    return
	
def p_triangle(s):
    t.pendown()
    for i in range(3):
        t.forward(s)
        t.right(120)
    t.penup()
    return

def r_color():
    red = r.randint(0,225)
    green = r.randint(0,225)
    blue = r.randint(0,225)
    color = (red,green,blue)
    return color

def c_square(s,c):
    t.pendown()
    t.fillcolor(c)
    t.begin_fill()
    p_square(s)
    t.end_fill()
    return
    
	
# main program
# draw first square
t.pendown()
t.pencolor("red")
t.fillcolor("orange")
t.begin_fill()
for i in range(4):
	t.forward(100)
	t.right(90)
t.end_fill()	
t.penup()


#second
t.forward(150)
t.pendown()
t.pencolor("blue")
t.fillcolor("purple")
t.begin_fill()
for i in range(4):
        t.forward(100)
        t.right(90)
t.end_fill()
t.penup()


#call functions
t.left(90)
t.forward(100)
square()
t.left(90)
t.forward(100)
rectangle()
t.forward(200)
triangle()
t.left(90)
t.forward(100)
p_square(70)
t.forward(100)
p_triangle(70)
t.forward(100)
t.colormode(255)
color = r_color()
side = r.randint(50,100)
c_square(side,color)
t.exitonclick()


