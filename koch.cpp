#include <iostream>
#include <GL/glut.h>
#include <math.h>

using namespace std;

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    gluOrtho2D(-360, 360, -270, 270);
    glClear(GL_COLOR_BUFFER_BIT);
}

float ang(float d) {
    return (float)d * M_PI / 180; // Use M_PI from math.h for pi
}

void draw_koch(float xa, float ya, float xb, float yb, int n) {
    float xc, xd, yc, yd, midx, midy;
    xc = (2 * xa + xb) / 3;
    yc = (2 * ya + yb) / 3;
    xd = (2 * xb + xa) / 3;
    yd = (2 * yb + ya) / 3;
    midx = xc + ((xd - xc) * cos(ang(60))) + ((yd - yc) * sin(ang(60)));
    midy = yc - ((xd - xc) * sin(ang(60))) + ((yd - yc) * cos(ang(60)));

    if (n > 0) {
        draw_koch(xa, ya, xc, yc, n - 1);
        draw_koch(xc, yc, midx, midy, n - 1);
        draw_koch(midx, midy, xd, yd, n - 1);
        draw_koch(xd, yd, xb, yb, n - 1);
    } else {
        glBegin(GL_LINES);
        glVertex2f(xa, ya);
        glVertex2f(xc, yc);
        glVertex2f(xc, yc);
        glVertex2f(midx, midy);
        glVertex2f(midx, midy);
        glVertex2f(xd, yd);
        glVertex2f(xd, yd);
        glVertex2f(xb, yb);
        glEnd();
    }
}

void draw(int n) {
    glBegin(GL_LINES);
    draw_koch(0, -200, 173.40, 100, n);
    draw_koch(173.40, 100, -173.40, 100, n);
    draw_koch(-173.40, 100, 0, -200, n);
    glEnd();
    glFlush();
}

int main(int argc, char **argv) {
    cout << "\n[Koch Curve]" << endl;
    int n;
    cout << "Enter the number of iterations (n): ";
    cin >> n;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(720, 540);
    glutCreateWindow("Koch Curve");
    init();
    draw(n);
    glutMainLoop();
    return 0;
}

