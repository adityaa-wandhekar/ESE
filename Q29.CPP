#include <graphics.h>
#include <math.h>

// Function to draw a Koch curve
void kochCurve(int x1, int y1, int x2, int y2, int iterations) {
    if (iterations == 0) {
        line(x1, y1, x2, y2);
        return;
    }

    // Calculate new points
    int deltaX = x2 - x1;
    int deltaY = y2 - y1;

    int x3 = x1 + deltaX / 3;
    int y3 = y1 + deltaY / 3;

    int x4 = (int)(0.5 * (x1 + x2) + sqrt(3) * (y1 - y2) / 6);
    int y4 = (int)(0.5 * (y1 + y2) + sqrt(3) * (x2 - x1) / 6);

    int x5 = x1 + 2 * deltaX / 3;
    int y5 = y1 + 2 * deltaY / 3;

    // Recursively draw the four segments of the Koch curve
    kochCurve(x1, y1, x3, y3, iterations - 1);
    kochCurve(x3, y3, x4, y4, iterations - 1);
    kochCurve(x4, y4, x5, y5, iterations - 1);
    kochCurve(x5, y5, x2, y2, iterations - 1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int x1 = 100, y1 = 200; // Start point
    int x2 = 500, y2 = 200; // End point
    int iterations = 4; // Number of iterations

    kochCurve(x1, y1, x2, y2, iterations);

    delay(5000);
    closegraph();
    return 0;
}