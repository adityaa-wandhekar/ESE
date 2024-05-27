//pendulum animation 
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include <dos.h>

// DDA Line Algorithm
void drawDDALine(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float x_inc = dx / (float) steps;
    float y_inc = dy / (float) steps;
    float x = x0;
    float y = y0;

    for (int i = 0; i <= steps; i++) {
        putpixel((int)x, (int)y, WHITE);
        x += x_inc;
        y += y_inc;
    }
}

// Bresenham's Circle Algorithm
void drawBresenhamCircle(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;
    while (y >= x) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
    }
}

// Function to draw pendulum
void drawPendulum(int xc, int yc, int length, float angle) {
    int x_end = xc + length * sin(angle);
    int y_end = yc + length * cos(angle);
    drawDDALine(xc, yc, x_end, y_end);
    drawBresenhamCircle(x_end, y_end, 10);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int xc = 320, yc = 100, length = 200;
    float angle = 0.0;
    float angle_step = 0.05;

    while (!kbhit()) {
        cleardevice();
        drawPendulum(xc, yc, length, angle);
        angle += angle_step;
        if (angle > 3.14 / 4 || angle < -3.14 / 4) {
            angle_step = -angle_step;
        }
        delay(50); // Adjust the delay to control the speed of the animation
    }

    closegraph();
    return 0;
}