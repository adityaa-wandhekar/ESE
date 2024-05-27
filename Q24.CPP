#include <graphics.h>
#include <stdio.h>
#include <math.h>

// Define a structure to represent a point
typedef struct {
    int x, y;
} Point;

// Function to draw a line between two points
void drawLine(Point p1, Point p2) {
    line(p1.x, p1.y, p2.x, p2.y);
}

// Function to rotate a point about an arbitrary point
void rotate(Point *p, Point pivot, float angle) {
    float rad = angle * (3.14159265 / 180); // Convert angle to radians
    int new_x = pivot.x + (p->x - pivot.x) * cos(rad) - (p->y - pivot.y) * sin(rad);
    int new_y = pivot.y + (p->x - pivot.x) * sin(rad) + (p->y - pivot.y) * cos(rad);
    p->x = new_x;
    p->y = new_y;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Define the arbitrary pivot point
    Point pivot = {200, 200};

    // Define the point to be rotated
    Point p = {300, 200};

    // Draw the original line
    setcolor(WHITE);
    drawLine(pivot, p);
    delay(1000);

    // Rotate the point about the pivot by 45 degrees
    float angle = 45.0;
    rotate(&p, pivot, angle);
    
    // Draw the rotated line
    setcolor(YELLOW);
    drawLine(pivot, p);

    delay(2000);
    closegraph();
    return 0;
}