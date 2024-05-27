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

// Function to reflect a point about the origin
void reflectOrigin(Point *p) {
    p->x = -p->x;
    p->y = -p->y;
}

// Function to reflect a point about the line Y = X
void reflectYX(Point *p) {
    int temp = p->x;
    p->x = p->y;
    p->y = temp;
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

    // Reflect about the origin
    Point p1_reflect_origin = p1, p2_reflect_origin = p2, p3_reflect_origin = p3;
    reflectOrigin(&p1_reflect_origin);
    reflectOrigin(&p2_reflect_origin);
    reflectOrigin(&p3_reflect_origin);
    setcolor(YELLOW);
    drawTriangle(p1_reflect_origin, p2_reflect_origin, p3_reflect_origin);
    delay(1000);

    // Reflect about the line Y = X
    Point p1_reflect_yx = p1, p2_reflect_yx = p2, p3_reflect_yx = p3;
    reflectYX(&p1_reflect_yx);
    reflectYX(&p2_reflect_yx);
    reflectYX(&p3_reflect_yx);
    setcolor(GREEN);
    drawTriangle(p1_reflect_yx, p2_reflect_yx, p3_reflect_yx);
    delay(1000);

    closegraph();
    return 0;
}