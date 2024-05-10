#include <iostream>
#include <math.h>
#include <GL/glut.h>

using namespace std;

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-360, 360, -270, 270);
}

void displayPoint(float x, float y) {
    glColor3f(0, 0, 0);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void drawCircle(float xc, float yc, float x, float y) {
    displayPoint(xc + x, yc + y);
    displayPoint(xc + x, yc - y);
    displayPoint(xc - x, yc + y);
    displayPoint(xc - x, yc - y);
    displayPoint(xc + y, yc + x);
    displayPoint(xc + y, yc - x);
    displayPoint(xc - y, yc + x);
    displayPoint(xc - y, yc - x);
}

void bresCircle(float xc, float yc, float r) {
    float x = 0, y = r;
    float d = 3 - 2 * r;
    drawCircle(xc, yc, x, y);
    while (y >= x) {
        x++;
        if (d >= 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else
            d = d + 4 * x + 6;
        drawCircle(xc, yc, x, y);
    }
    glFlush();
}

float ang(float d) {
    return (float)d * 3.142 / 180;
}

float xc0, yc0, r0;

void drawing() {
    glClear(GL_COLOR_BUFFER_BIT);
    bresCircle(xc0, yc0, r0);
    bresCircle(xc0 + r0 * sin(ang(0)), yc0 + r0 * cos(ang(0)), r0);
    bresCircle(xc0 + r0 * sin(ang(45)), yc0 + r0 * cos(ang(45)), r0);
    bresCircle(xc0 + r0 * sin(ang(90)), yc0 + r0 * cos(ang(90)), r0);
    bresCircle(xc0 + r0 * sin(ang(135)), yc0 + r0 * cos(ang(135)), r0);
    bresCircle(xc0 + r0 * sin(ang(180)), yc0 + r0 * cos(ang(180)), r0);
    bresCircle(xc0 + r0 * sin(ang(225)), yc0 + r0 * cos(ang(225)), r0);
    bresCircle(xc0 + r0 * sin(ang(270)), yc0 + r0 * cos(ang(270)), r0);
    bresCircle(xc0 + r0 * sin(ang(315)), yc0 + r0 * cos(ang(315)), r0);
    bresCircle(xc0, yc0, 2 * r0);
    glFlush();
}

int main(int argc, char **argv) {
    cout << "\n[Note that the x values range from -360 to 360 and y values from -270 to 270]" << endl;
    cout << "\nEnter the centre (x, y) of the central circle: ";
    cin >> xc0 >> yc0;
    cout << "\nEnter the radius of the central circle: ";
    cin >> r0;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(720, 540);
    glutCreateWindow("‭Many circle");
    init();
    glutDisplayFunc(drawing);
    glutMainLoop();
    return 0;
}

