//clock animation 
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

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

// Function to draw clock hands
void drawClockHands(int xc, int yc, float angle, int length) {
    int x = xc + length * cos(angle);
    int y = yc - length * sin(angle);
    drawDDALine(xc, yc, x, y);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int xc = 300, yc = 300, radius = 150;
    int sec_length = 140, min_length = 120, hour_length = 80;

    while (!kbhit()) {
        // Clear screen
        cleardevice();

        // Draw clock face
        drawBresenhamCircle(xc, yc, radius);

        // Get current time
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        int hours = t->tm_hour;
        int minutes = t->tm_min;
        int seconds = t->tm_sec;

        // Draw hour hand
        float hour_angle = (hours % 12 + minutes / 60.0) * 30.0 * M_PI / 180.0;
        drawClockHands(xc, yc, hour_angle, hour_length);

        // Draw minute hand
        float minute_angle = (minutes + seconds / 60.0) * 6.0 * M_PI / 180.0;
        drawClockHands(xc, yc, minute_angle, min_length);

        // Draw second hand
        float second_angle = seconds * 6.0 * M_PI / 180.0;
        drawClockHands(xc, yc, second_angle, sec_length);

        delay(1000); // Wait for 1 second
    }

    closegraph();
    return 0;
}