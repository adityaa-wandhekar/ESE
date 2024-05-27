#include <graphics.h>
#include <stdio.h>

// Define a structure to represent a point
typedef struct {
    int x, y;
} Point;

// Function to draw a triangle given three points
void drawTriangle(Point p1, Point p2, Point p3) {
    line(p1.x, p1.y, p2.x, p2.y);
    line(p2.x, p2.y, p3.x, p3.y);
    line(p3.x, p3.y, p1.x, p1.y);
}

// Function to reflect a point about the X-axis
void reflectX(Point *p) {
    p->y = -p->y;
}

// Function to reflect a point about the Y-axis
void reflectY(Point *p) {
    p->x = -p->x;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Define the vertices of the triangle
    Point p1 = {100, 100};
    Point p2 = {200, 100};
    Point p3 = {150, 200};

    // Draw the original triangle
    setcolor(WHITE);
    drawTriangle(p1, p2, p3);
    delay(1000);

    // Reflect about the X-axis
    Point p1_reflect_x = p1, p2_reflect_x = p2, p3_reflect_x = p3;
    reflectX(&p1_reflect_x);
    reflectX(&p2_reflect_x);
    reflectX(&p3_reflect_x);
    setcolor(YELLOW);
    drawTriangle(p1_reflect_x, p2_reflect_x, p3_reflect_x);
    delay(1000);

    // Reflect about the Y-axis
    Point p1_reflect_y = p1, p2_reflect_y = p2, p3_reflect_y = p3;
    reflectY(&p1_reflect_y);
    reflectY(&p2_reflect_y);
    reflectY(&p3_reflect_y);
    setcolor(GREEN);
    drawTriangle(p1_reflect_y, p2_reflect_y, p3_reflect_y);
    delay(1000);

    closegraph();
    return 0;
}