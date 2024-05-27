#include <graphics.h>
#include <stdio.h>

// Define region codes
#define INSIDE 0  // 0000
#define LEFT 1    // 0001
#define RIGHT 2   // 0010
#define BOTTOM 4  // 0100
#define TOP 8     // 1000

// Define the window coordinates
#define X_MIN 100
#define Y_MIN 100
#define X_MAX 400
#define Y_MAX 300

// Define a structure to represent a point
typedef struct {
    int x, y;
} Point;

// Function to calculate region code for a point
int calculateCode(Point p) {
    int code = INSIDE;
    if (p.x < X_MIN)
        code |= LEFT;
    else if (p.x > X_MAX)
        code |= RIGHT;
    if (p.y < Y_MIN)
        code |= BOTTOM;
    else if (p.y > Y_MAX)
        code |= TOP;
    return code;
}

// Function to clip a line using Cohen-Sutherland algorithm
void cohenSutherland(Point p1, Point p2) {
    int code1 = calculateCode(p1);
    int code2 = calculateCode(p2);
    int accept = 0;

    while (1) {
        if (!(code1 | code2)) {
            // Both endpoints lie inside the window
            accept = 1;
            break;
        } else if (code1 & code2) {
            // Both endpoints are outside the window and on the same side
            break;
        } else {
            // Some portion of the line lies inside the window
            int code_out;
            Point p;
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            if (code_out & TOP) {
                // Point is above the window
                p.x = p1.x + (p2.x - p1.x) * (Y_MAX - p1.y) / (p2.y - p1.y);
                p.y = Y_MAX;
            } else if (code_out & BOTTOM) {
                // Point is below the window
                p.x = p1.x + (p2.x - p1.x) * (Y_MIN - p1.y) / (p2.y - p1.y);
                p.y = Y_MIN;
            } else if (code_out & RIGHT) {
                // Point is to the right of the window
                p.y = p1.y + (p2.y - p1.y) * (X_MAX - p1.x) / (p2.x - p1.x);
                p.x = X_MAX;
            } else if (code_out & LEFT) {
                // Point is to the left of the window
                p.y = p1.y + (p2.y - p1.y) * (X_MIN - p1.x) / (p2.x - p1.x);
                p.x = X_MIN;
            }

            if (code_out == code1) {
                p1 = p;
                code1 = calculateCode(p1);
            } else {
                p2 = p;
                code2 = calculateCode(p2);
            }
        }
    }

    if (accept) {
        setcolor(YELLOW);
        line(p1.x, p1.y, p2.x, p2.y);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Draw the clipping window
    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);

    // Define the line endpoints
    Point p1 = {50, 200};
    Point p2 = {500, 100};

    // Draw the original line
    setcolor(WHITE);
    line(p1.x, p1.y, p2.x, p2.y);

    // Clip the line using Cohen-Sutherland algorithm
    cohenSutherland(p1, p2);

    delay(5000);
    closegraph();
    return 0;
}