#include <iostream>
#include <math.h>
#include <GL/glut.h>

using namespace std;

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0); // Set display-window color to white
    glMatrixMode(GL_PROJECTION); // Set projection parameters
    gluOrtho2D(-360, 360, -270, 270); // To define coordinate reference (LRBT) frame within the display window
    glMatrixMode(GL_MODELVIEW); // Set matrix mode to modelview
}

void displayPoint(float x, float y) {
    glColor3f(0, 0, 0);
    glPointSize(1);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void drawCircle(float xc, float yc, float x, float y) {
    displayPoint(xc + x, yc + y);
    displayPoint(xc - x, yc + y);
    displayPoint(xc + x, yc - y);
    displayPoint(xc - x, yc - y);
    displayPoint(xc + y, yc + x);
    displayPoint(xc - y, yc + x);
    displayPoint(xc + y, yc - x);
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
        } else {
            d = d + 4 * x + 6;
        }
        drawCircle(xc, yc, x, y);
    }
}

float xc0, yc0;

void drawing() {
    glClear(GL_COLOR_BUFFER_BIT);
    bresCircle(xc0, yc0, 40);
    bresCircle(xc0 + 64, yc0 + 14, 25);
    bresCircle(xc0 + 106, yc0 + 42, 25);
    bresCircle(xc0 + 141, yc0 + 78, 25);
    bresCircle(xc0 + 158, yc0 + 126, 25);
    bresCircle(xc0 + 160, yc0 + 177, 25);
    bresCircle(xc0 - 64, yc0 + 14, 25);
    bresCircle(xc0 - 106, yc0 + 42, 25);
    bresCircle(xc0 - 141, yc0 + 78, 25);
    bresCircle(xc0 - 158, yc0 + 126, 25);
    bresCircle(xc0 - 160, yc0 + 177, 25);
    bresCircle(xc0, yc0 - 66, 25);
    bresCircle(xc0 + 46, yc0 - 46, 25);
    bresCircle(xc0 - 46, yc0 - 46, 25);
    bresCircle(xc0, yc0 - 117, 25);
    glFlush();
}

int main(int argc, char **argv) {
    cout << "\n[Note that the x values range from -360 to 360 and y values from -270 to 270]" << endl;
    cout << "\nEnter the centre (x, y) of the middle bead of the necklace: ";
    cin >> xc0 >> yc0;

    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowPosition(50, 100); // Set top-left display-window position
    glutInitWindowSize(720, 540); // Set display-window width and height
    glutCreateWindow("‭Necklace Pattern‬"); // Create display window
    init();
    glutDisplayFunc(drawing);
    glutMainLoop();
    return 0;
}

