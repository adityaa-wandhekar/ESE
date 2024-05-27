#include <graphics.h>
#include <conio.h>
#include <math.h>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to scale a triangle
void scaleTriangle(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, float sx, float sy) {
    *x1 = (int)(*x1 * sx);
    *y1 = (int)(*y1 * sy);
    *x2 = (int)(*x2 * sx);
    *y2 = (int)(*y2 * sy);
    *x3 = (int)(*x3 * sx);
    *y3 = (int)(*y3 * sy);
}

// Function to rotate a triangle
void rotateTriangle(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, float angle) {
    float rad = angle * M_PI / 180.0; // Convert angle to radians
    int tx1 = *x1, ty1 = *y1;
    int tx2 = *x2, ty2 = *y2;
    int tx3 = *x3, ty3 = *y3;

    *x1 = (int)(tx1 * cos(rad) - ty1 * sin(rad));
    *y1 = (int)(tx1 * sin(rad) + ty1 * cos(rad));
    *x2 = (int)(tx2 * cos(rad) - ty2 * sin(rad));
    *y2 = (int)(tx2 * sin(rad) + ty2 * cos(rad));
    *x3 = (int)(tx3 * cos(rad) - ty3 * sin(rad));
    *y3 = (int)(tx3 * sin(rad) + ty3 * cos(rad));
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Original coordinates of the triangle
    int x1 = 100, y1 = 100;
    int x2 = 150, y2 = 50;
    int x3 = 200, y3 = 100;

    // Scaling factors
    float sx = 1.5, sy = 1.5;
    
    // Rotation angle
    float angle = 45.0;

    // Draw original triangle
    setcolor(WHITE);
    drawTriangle(x1, y1, x2, y2, x3, y3);

    // Scale the triangle
    scaleTriangle(&x1, &y1, &x2, &y2, &x3, &y3, sx, sy);
    
    // Draw scaled triangle
    setcolor(RED);
    drawTriangle(x1, y1, x2, y2, x3, y3);

    // Rotate the triangle
    rotateTriangle(&x1, &y1, &x2, &y2, &x3, &y3, angle);

    // Draw rotated triangle
    setcolor(GREEN);
    drawTriangle(x1, y1, x2, y2, x3, y3);

    getch();
    closegraph();
    return 0;
}
