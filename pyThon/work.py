import turtle

def drawPic(size, cnt):
    if cnt == 0:
        turtle.fd(size)
    else:
        for angle in [0, 90, -90, -90, 90]:
            turtle.left(angle)
            drawPic(size / 3, cnt - 1)

def main():
    turtle.setup(1200, 1200)
    turtle.speed(1000000)
    turtle.penup()
    turtle.goto(-200, 200)
    turtle.pendown()
    turtle.pensize(2)    
    l = 4
    drawPic(400, l)
    turtle.right(90)
    drawPic(400, l)
    turtle.right(90)
    drawPic(400, l)
    turtle.right(90)
    drawPic(400, l)
    turtle.hideturtle()

main()


