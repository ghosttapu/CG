#include <iostream>
#include <GL/glut.h>

using namespace std;

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0); // Set display-window color to white
    glMatrixMode(GL_PROJECTION); // Set projection parameters
    gluOrtho2D(-360, 360, 270, -270); // To define coordinate reference (LRBT) frame within the display window
}

void displayPoint(float x, float y) {
    glColor3f(0, 0, 0);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void ddaLine(float x1, float y1, float x2, float y2) {
    float step;
    float dx = x2 - x1;
    float dy = y2 - y1;
    if (abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);
    float xinc = dx / step;
    float yinc = dy / step;
    float x = x1;
    float y = y1;
    for (int i = 0; i <= step; i++) {
        displayPoint(x, y);
        x = x + xinc;
        y = y + yinc;
    }
}

void drawing() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear display window

    // Staircase Pattern
    ddaLine(-150, 150, -150, 100);
    ddaLine(-150, 100, -100, 100);
    ddaLine(-100, 100, -100, 50);
    ddaLine(-100, 50, -50, 50);
    ddaLine(-50, 50, -50, 0);
    ddaLine(-50, 0, 0, 0);
    ddaLine(0, 0, 0, -50);
    ddaLine(0, -50, 50, -50);
    ddaLine(50, -50, 50, -100);
    ddaLine(50, -100, 100, -100);
    ddaLine(100, -100, 100, -150);
    ddaLine(100, -150, 150, -150);
    ddaLine(150, -150, 150, 150);
    ddaLine(150, 150, -150, 150);

    glFlush(); // Process all OpenGL routines as quickly as possible
}

int main(int argc, char **argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowPosition(50, 100); // Set top-left display-window position
    glutInitWindowSize(720, 540); // Set display-window width and height
    glutCreateWindow("DDA stair"); // Create display window
    init();
    glutDisplayFunc(drawing);
    glutMainLoop(); // Execute initialization procedure

    return 0;
}

