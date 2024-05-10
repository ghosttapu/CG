#include <stdio.h>
#include <math.h>
#include <GL/freeglut.h>
#include <GL/gl.h>

int xf1, yf1; // Coordinates for the first point
bool selected = false; // Flag to track if a point is selected
int l; // Length of the pattern

void plot(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void bresenham(int x1, int y1, int x2, int y2) {
    // Bresenham's line drawing algorithm implementation
    // ...
}

void draw_pattern() {
    // Draw the staircase pattern
    // ...
}

void init() {
    glClearColor(1.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void mouse(int button, int state, int x, int y) {
    // Mouse click handling
    // ...
}

int main(int argc, char **argv) {
    printf("\nEnter length of the pattern: ");
    scanf("%d", &l);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Staircase");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}

