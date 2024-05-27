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

// Function to translate a triangle
void translateTriangle(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, int tx, int ty) {
    *x1 = *x1 + tx;
    *y1 = *y1 + ty;
    *x2 = *x2 + tx;
    *y2 = *y2 + ty;
    *x3 = *x3 + tx;
    *y3 = *y3 + ty;
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

    // Translation factors
    int tx =250, ty = 0;

    // Draw original triangle
    setcolor(WHITE);
    drawTriangle(x1, y1, x2, y2, x3, y3);

    // Scale the triangle
    scaleTriangle(&x1, &y1, &x2, &y2, &x3, &y3, sx, sy);

    // Draw scaled triangle
    setcolor(RED);
    drawTriangle(x1, y1, x2, y2, x3, y3);

    // Translate the triangle
    translateTriangle(&x1, &y1, &x2, &y2, &x3, &y3, tx, ty);

    // Draw translated triangle
    setcolor(GREEN);
    drawTriangle(x1, y1, x2, y2, x3, y3);

    getch();
    closegraph();
    return 0;
}
