#include <iostream>
#include <GL/glut.h>
using namespace std;

void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-360, 360, -270, 270);
}

void displayPoint(float x, float y)
{
    glColor3f(0, 0, 0);
    glPointSize(1);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}
void displayLine()
{
    glColor3f(0, 0, 0);
    glPointSize(1);
    glBegin(GL_LINES);
    glVertex2i(-40, -30);
    glVertex2i(40, -30);
    glEnd();
}
void bresLine(float x1, float y1, float x2, float y2)
{
    float p, xinc, yinc, pinc1, pinc2;
    float dx = x2 - x1;
    float dy = y2 - y1;
    float x = x1;
    float y = y1;

    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;

    xinc = 1;
    if (x2 < x1)
        xinc = -1;
    yinc = 1;
    if (y2 < y1)
        yinc = -1;

    displayPoint(x, y);

    if (dx > dy)
    {
        p = 2 * dy - dx;
        pinc1 = 2 * (dy - dx);
        pinc2 = 2 * dy;

        for (int i = 0; i < (int)dx; i++)
        {
            if (p >= 0)
            {
                y = y + yinc;
                p = p + pinc1;
            }
            else
                p = p + pinc2;
            x = x + xinc;

            displayPoint(x, y);
        }
    }
    else // abs(dx) <= abs (dy)
    {
        p = 2 * dx - dy;
        pinc1 = 2 * (dx - dy);
        pinc2 = 2 * dx;

        for (int i = 0; i < (int)dy; i++)
        {
            if (p >= 0)
            {
                x = x + xinc;
                p = p + pinc1;
            }
            else
                p = p + pinc2;
            y = y + yinc;

            displayPoint(x, y);
        }
    }

    glFlush();
}

void drawCircle(float xc, float yc, float x, float y)
{
    displayPoint(xc + x, yc + y);
    displayPoint(xc + x, yc - y);
    displayPoint(xc - x, yc + y);
    displayPoint(xc - x, yc - y);
    displayPoint(xc + y, yc + x);
    displayPoint(xc + y, yc - x);
    displayPoint(xc - y, yc + x);
    displayPoint(xc - y, yc - x);
}

void bresCircle(float xc, float yc, float r)
{
    float x = 0, y = r;
    float d = 3 - 2 * r;

    drawCircle(xc, yc, x, y);
    while (y >= x)
    {
        x++;
        if (d >= 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        drawCircle(xc, yc, x, y);
    }

    glFlush();
}
void drawSemicircle(float xc, float yc, float x, float y)
{

    displayPoint(xc + x, yc - y);

    displayPoint(xc - x, yc - y);

    displayPoint(xc + y, yc - x);
    displayPoint(xc - y, yc - x);
}

void bresSemicircle(float xc, float yc, float r)
{
    float x = 0, y = r;
    float d = 3 - 2 * r;

    drawSemicircle(xc, yc, x, y);
    while (y >= x)
    {
        x++;
        if (d >= 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        drawSemicircle(xc, yc, x, y);
    }
}

void drawing()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw circles
    bresCircle(0, 0, 100);
    bresCircle(35.3553, 35.3553, 25);
    bresCircle(-35.3553, 35.3553, 25);
    bresSemicircle(0, -30, 40);
    bresLine(-40, -30, 40, -30);

    glColor3f(1.0, 0.0, 0.0);


    glFlush(); 
}

int main(int argc, char **argv) 
{
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RED);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(720, 540);
    glutCreateWindow("Bresenham Circle Drawing Algorithm");

    init();
    glutDisplayFunc(drawing);
    glutMainLoop();

    return 0;
}
