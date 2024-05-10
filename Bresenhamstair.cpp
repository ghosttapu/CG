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
            }
            else
                p = p + pinc2;
            x = x + xinc;
            displayPoint(x, y);
        }
    }
    else { // abs(dx) <= abs (dy)
        p = 2 * dx - dy;
        pinc1 = 2 * (dx - dy);
        pinc2 = 2 * dx;
        for (int i = 0; i < (int)dy; i++) {
            if (p >= 0) {
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

void drawing() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear display window
    // Staircase Pattern
    bresLine(-150, 150, -150, 100);
    bresLine(-150, 100, -100, 100);
    bresLine(-100, 100, -100, 50);
    bresLine(-100, 50, -50, 50);
    bresLine(-50, 50, -50, 0);
    bresLine(-50, 0, 0, 0);
    bresLine(0, 0, 0, -50);
    bresLine(0, -50, 50, -50);
    bresLine(50, -50, 50, -100);
    bresLine(50, -100, 100, -100);
    bresLine(100, -100, 100, -150);
    bresLine(100, -150, 150, -150);
    bresLine(150, -150, 150, 150);
    bresLine(150, 150, -150, 150);
    glFlush(); // Process all OpenGL routines as quickly as possible (To put changed pixel in frame buffer)
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowPosition(50, 100); // Set top-left display-window position
    glutInitWindowSize(720, 540); // Set display-window width and height
    glutCreateWindow("‭Bresenham staircase‬"); // Create display window
    init();
    glutDisplayFunc(drawing);
    glutMainLoop(); // Execute initialization procedure
    // Send graphics to display window
    return 0;
}

