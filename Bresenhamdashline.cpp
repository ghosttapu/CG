#include <iostream>
#include <GL/glut.h>

using namespace std;

struct Point
{
    float x;
    float y;
};

Point P, Q, A1, A2, B1, B2, B3, B4, C1, C2, C3, C4;

void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // Set display-window color to white
    glMatrixMode(GL_PROJECTION);      // Set projection parameters
    gluOrtho2D(-360, 360, -270, 270); // To define coordinate reference (LRBT) frame within the display window
}

void displayPoint(float x, float y)
{
    glColor3f(0, 0, 0);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void pointCalculations()
{
    A1.x = P.x;
    A1.y = Q.y;
    A2.x = Q.x;
    A2.y = P.y;
    B1.x = (A1.x + P.x) / 2;
    B1.y = (A1.y + P.y) / 2;
    B2.x = (A1.x + Q.x) / 2;
    B2.y = (A1.y + Q.y) / 2;
    B3.x = (Q.x + A2.x) / 2;
    B3.y = (Q.y + A2.y) / 2;
    B4.x = (P.x + A2.x) / 2;
    B4.y = (P.y + A2.y) / 2;
    C1.x = (B1.x + B2.x) / 2;
    C1.y = (B1.y + B2.y) / 2;
    C2.x = (B2.x + B3.x) / 2;
    C2.y = (B2.y + B3.y) / 2;
    C3.x = (B3.x + B4.x) / 2;
    C3.y = (B3.y + B4.y) / 2;
    C4.x = (B4.x + B1.x) / 2;
    C4.y = (B4.y + B1.y) / 2;
}

void bresDashLine(float x1, float y1, float x2, float y2)
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
            if (i % 11 == 3 || i % 11 == 4 || i % 11 == 5 || i % 11 == 6 || i % 11 == 7 || i % 11 == 8 || i % 11 == 9 || i % 11 == 10)
                displayPoint(x, y);
        }
    }
    else // (dx) <= (dy)
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
            if (i % 11 == 3 || i % 11 == 4 || i % 11 == 5 || i % 11 == 6 || i % 11 == 7 || i % 11 == 8 || i % 11 == 9 || i % 11 == 10)
                displayPoint(x, y);
        }
    }
    glFlush();
}

void drawing()
{
    glClear(GL_COLOR_BUFFER_BIT);
    bresDashLine(A1.x, A1.y, Q.x, Q.y);
    bresDashLine(Q.x, Q.y, A2.x, A2.y);
    bresDashLine(A2.x, A2.y, P.x, P.y);
    bresDashLine(P.x, P.y, A1.x, A1.y);
    bresDashLine(B1.x, B1.y, B2.x, B2.y);
    bresDashLine(B2.x, B2.y, B3.x, B3.y);
    bresDashLine(B3.x, B3.y, B4.x, B4.y);
    bresDashLine(B4.x, B4.y, B1.x, B1.y);
    bresDashLine(C1.x, C1.y, C2.x, C2.y);
    bresDashLine(C2.x, C2.y, C3.x, C3.y);
    bresDashLine(C3.x, C3.y, C4.x, C4.y);
    bresDashLine(C4.x, C4.y, C1.x, C1.y);
    glFlush();
}

int main(int argc, char **argv)
{
    cout << "\n[Note that the x values range from -360 to 360 and y values from -270 to 270]" << endl;
    cout << "\nEnter the float coordinates (x, y) for the point P (bottom-left corner): ";
    cin >> P.x >> P.y;
    cout << "Enter the float coordinates (x, y) for the point Q (top-right corner): ";
    cin >> Q.x >> Q.y;
    pointCalculations();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(720, 540);
    glutCreateWindow("dashLine bresenham pattern‬");
    init();
    glutDisplayFunc(drawing);
    glutMainLoop();
    return 0;
}

