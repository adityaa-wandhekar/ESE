#include <graphics.h>
#include <stdio.h>

// Define a structure to represent a point
typedef struct {
    int x, y;
} Point;

// Function to draw a rectangle given two points
void drawRectangle(Point p1, Point p2) {
    rectangle(p1.x, p1.y, p2.x, p2.y);
}

// Function to perform X shear transformation
void shearX(Point *p, float shx) {
    p->x = p->x + shx * p->y;
}

// Function to perform Y shear transformation
void shearY(Point *p, float shy) {
    p->y = p->y + shy * p->x;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Define the vertices of the rectangle
    Point p1 = {100, 100};
    Point p2 = {200, 200};

    // Draw the original rectangle
    setcolor(WHITE);
    drawRectangle(p1, p2);
    delay(1000);

    // Shear along X-axis
    Point p1_shear_x = p1, p2_shear_x = p2;
    float shx = 0.5; // Shear factor along X-axis
    shearX(&p1_shear_x, shx);
    shearX(&p2_shear_x, shx);
    setcolor(YELLOW);
    drawRectangle(p1_shear_x, p2_shear_x);
    delay(1000);

    // Shear along Y-axis
    Point p1_shear_y = p1, p2_shear_y = p2;
    float shy = 0.5; // Shear factor along Y-axis
    shearY(&p1_shear_y, shy);
    shearY(&p2_shear_y, shy);
    setcolor(GREEN);
    drawRectangle(p1_shear_y, p2_shear_y);
    delay(1000);

    closegraph();
    return 0;
}