#include <iostream>
#include <GL/glut.h>
#include <cmath>

using namespace std;

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0); // Set display-window color to white
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-360, 360, 270, -270); // Set projection parameters
}

void displayPoint(float x, float y) {
    glColor3f(0, 0, 0);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void bresLine(float x1, float y1, float x2, float y2) {
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
    if (dx > dy) {
        p = 2 * dy - dx;
        pinc1 = 2 * (dy - dx);
        pinc2 = 2 * dy;
        for (int i = 0; i < (int)dx; i++) {
            if (p >= 0) {
                y = y + yinc;
                p = p + pinc1;
            } else
                p = p + pinc2;
            x = x + xinc;
            displayPoint(x, y);
        }
    } else {
        p = 2 * dx - dy;
        pinc1 = 2 * (dx - dy);
        pinc2 = 2 * dx;
        for (int i = 0; i < (int)dy; i++) {
            if (p >= 0) {
                x = x + xinc;
                p = p + pinc1;
            } else
                p = p + pinc2;
            y = y + yinc;
            displayPoint(x, y);
        }
    }
}

void drawing() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear display window

    // Outer Rectangle
    bresLine(-220, -158, 220, -158);
    bresLine(220, -158, 220, 107);
    bresLine(220, 107, -220, 107);
    bresLine(-220, 107, -220, -158);

    // Inner Rectangle
    bresLine(-200, -138, 200, -138);
    bresLine(200, -138, 200, 87);
    bresLine(200, 87, -200, 87);
    bresLine(-200, 87, -200, -138);

    // Base Trapezium
    bresLine(-75, 107, 75, 107);
    bresLine(75, 107, 100, 157);
    bresLine(100, 157, -100, 157);
    bresLine(-100, 157, -75, 107);

    // Triangle-1
    bresLine(-200, 87, -120, 0);
    bresLine(-120, 0, -30, 87);
    bresLine(-30, 87, -200, 87);

    // Triangle-2
    bresLine(-30, 87, 60, -60);
    bresLine(60, -60, 200, 87);
    bresLine(200, 87, -30, 87);

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(720, 540);
    glutCreateWindow("Bersham window");
    init();
    glutDisplayFunc(drawing);
    glutMainLoop();
    return 0;
}

