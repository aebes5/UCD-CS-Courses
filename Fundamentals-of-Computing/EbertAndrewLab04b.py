#9/15/2022
# We will draw some simple objects using the graphics package
#graphics.py

from graphics import *

import time

def main():
    winName = input("What would you like the name of the window to be?")
    color = input("What color would you like the circle to be?")
    x1, y1 = eval(input("What are the x, y coordinates of the center of the circle?"))
    rad = eval(input("What is the radius of the circle?"))

    win = GraphWin(winName, 500, 500)
    cent = Point(x1, y1)
    circ = Circle(cent, rad)
    circ.setFill(color)
    circ.draw(win)

    x2 = x1
    y2 = y1 - (2 * rad)
    cent2 = Point(x2, y2)
    circ2 = Circle(cent2, (1/2 * rad))
    circ2.setFill('green')
    circ2.draw(win)

    line = Line(cent, cent2)
    line.setFill('red')
    line.draw(win)
    win.getMouse()
    line.undraw()
    time.sleep(2)

    
    win.getMouse()

    circ2.move(40,40)
    cent2 = circ2.getCenter()
    line=Line(cent, cent2)
    line.setFill('red')
    line.draw(win)
    win.getMouse()
    line.undraw()
    time.sleep(2)

    win.getMouse()

    circ2.move(-40,40)
    cent2 = circ2.getCenter()
    line=Line(cent, cent2)
    line.setFill('red')
    line.draw(win)
    win.getMouse()
    line.undraw()
    time.sleep(2)
    
    win.getMouse()

    circ2.move(-40,-40)
    cent2 = circ2.getCenter()
    line=Line(cent, cent2)
    line.setFill('red')
    line.draw(win)
    win.getMouse()
    line.undraw()
    time.sleep(2)

    win.getMouse()

    circ2.move(40,-40)
    cent2 = circ2.getCenter()
    line=Line(cent, cent2)
    line.setFill('red')
    line.draw(win)
    win.getMouse()
    line.undraw()
    time.sleep(2)
