#include <graphics.h>
#include <math.h>

// Function to draw a Hilbert curve
void hilbertCurve(int x, int y, int length, char direction, int iterations) {
    if (iterations <= 0)
        return;

    length /= 2;

    if (direction == 'U') {
        hilbertCurve(x, y + length, length, 'L', iterations - 1);
        line(x, y, x, y + length);
        hilbertCurve(x, y + length, length, 'U', iterations - 1);
        line(x, y + length, x + length, y + length);
        hilbertCurve(x + length, y + length, length, 'U', iterations - 1);
        line(x + length, y, x + length, y + length);
        hilbertCurve(x + length, y, length, 'R', iterations - 1);
    } else if (direction == 'D') {
        hilbertCurve(x, y, length, 'R', iterations - 1);
        line(x, y, x + length, y);
        hilbertCurve(x + length, y, length, 'D', iterations - 1);
        line(x, y + length, x + length, y + length);
        hilbertCurve(x, y + length, length, 'D', iterations - 1);
        line(x, y, x, y + length);
        hilbertCurve(x, y, length, 'L', iterations - 1);
    } else if (direction == 'L') {
        hilbertCurve(x + length, y, length, 'D', iterations - 1);
        line(x, y, x + length, y);
        hilbertCurve(x, y, length, 'L', iterations - 1);
        line(x, y, x, y + length);
        hilbertCurve(x, y + length, length, 'L', iterations - 1);
        line(x, y + length, x + length, y + length);
        hilbertCurve(x + length, y + length, length, 'U', iterations - 1);
    } else if (direction == 'R') {
        hilbertCurve(x, y + length, length, 'U', iterations - 1);
        line(x, y, x, y + length);
        hilbertCurve(x, y, length, 'R', iterations - 1);
        line(x + length, y, x + length, y + length);
        hilbertCurve(x + length, y, length, 'R', iterations - 1);
        line(x, y + length, x + length, y + length);
        hilbertCurve(x, y + length, length, 'D', iterations - 1);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int x = 50, y = 50; // Starting position
    int length = 400; // Length of the Hilbert curve
    char direction = 'U'; // Initial direction (U, D, L, R)
    int iterations = 3; // Number of iterations

    hilbertCurve(x, y, length, direction, iterations);

    delay(5000);
    closegraph();
    return 0;
}