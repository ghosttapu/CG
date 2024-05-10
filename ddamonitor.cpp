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
    float xinc = dx / (float)step;
    float yinc = dy / (float)step;
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

    // Outer Rectangle
    ddaLine(-220, -158, 220, -158);
    ddaLine(220, -158, 220, 107);
    ddaLine(220, 107, -220, 107);
    ddaLine(-220, 107, -220, -158);

    // Inner Rectangle
    ddaLine(-200, -138, 200, -138);
    ddaLine(200, -138, 200, 87);
    ddaLine(200, 87, -200, 87);
    ddaLine(-200, 87, -200, -138);

    // Base Trapezium
    ddaLine(-75, 107, 75, 107);
    ddaLine(75, 107, 100, 157);
    ddaLine(100, 157, -100, 157);
    ddaLine(-100, 157, -75, 107);

    // Triangle-1
    ddaLine(-200, 87, -120, 0);
    ddaLine(-120, 0, -30, 87);
    ddaLine(-30, 87, -200, 87);

    // Triangle-2
    ddaLine(-30, 87, 60, -60);
    ddaLine(60, -60, 200, 87);
    ddaLine(200, 87, -30, 87);

    glFlush(); // Process all OpenGL routines as quickly as possible
}

int main(int argc, char **argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowPosition(50, 100); // Set top-left display-window position
    glutInitWindowSize(720, 540); // Set display-window width and height
    glutCreateWindow("‭DDA monitor mountain‬"); // Create display window
    init(); // Execute initialization procedure
    glutDisplayFunc(drawing); // Send graphics to display window
    glutMainLoop();
    return 0;
}

