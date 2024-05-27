#include <graphics.h>

// Function to calculate the midpoint between two points
void midpoint(Point *p1, Point *p2, Point *mid) {
    mid->x = (p1->x + p2->x) / 2;
    mid->y = (p1->y + p2->y) / 2;
}

// Function to calculate the control point of a Bezier curve
void bezierControlPoint(Point *p1, Point *p2, Point *control) {
    control->x = (2 * p1->x + p2->x) / 3;
    control->y = (2 * p1->y + p2->y) / 3;
}

// Function to draw a Bezier curve
void drawBezier(Point *points, int n, int iterations) {
    if (n == 1) {
        line(points[0].x, points[0].y, points[1].x, points[1].y);
        return;
    }

    Point midpoints[10];
    for (int i = 0; i < n - 1; i++) {
        midpoint(&points[i], &points[i + 1], &midpoints[i]);
    }

    Point controlPoints[10];
    for (int i = 0; i < n - 2; i++) {
        bezierControlPoint(&midpoints[i], &midpoints[i + 1], &controlPoints[i]);
    }

    Point nextPoints[10];
    for (int i = 0; i < n - 2; i++) {
        nextPoints[i * 2] = points[i];
        nextPoints[i * 2 + 1] = controlPoints[i];
    }
    nextPoints[(n - 2) * 2] = points[n - 2];
    nextPoints[(n - 2) * 2 + 1] = midpoints[n - 2];
    nextPoints[(n - 2) * 2 + 2] = points[n - 1];

    drawBezier(nextPoints, (n - 1) * 2 + 1, iterations - 1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    Point points[] = {{100, 300}, {200, 100}, {300, 300}, {400, 100}, {500, 300}};
    int numPoints = sizeof(points) / sizeof(points[0]);

    int iterations = 4;

    drawBezier(points, numPoints, iterations);

    delay(5000);
    closegraph();
    return 0;
}