#include <graphics.h>
#include <stdio.h>

#define MAX_POINTS 20

// Define the window coordinates
#define X_MIN 100
#define Y_MIN 100
#define X_MAX 400
#define Y_MAX 300

// Define a structure to represent a point
typedef struct {
    int x, y;
} Point;

// Function to draw a rectangle representing the clipping window
void drawWindow() {
    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);
}

// Function to draw a polygon
void drawPolygon(Point *polygon, int numVertices) {
    int i;
    for (i = 0; i < numVertices; i++) {
        int j = (i + 1) % numVertices;
        line(polygon[i].x, polygon[i].y, polygon[j].x, polygon[j].y);
    }
}

// Function to calculate the intersection point of two line segments
Point calculateIntersection(Point p1, Point p2, int edge) {
    Point intersection;
    if (edge == LEFT) {
        intersection.x = X_MIN;
        intersection.y = p1.y + (p2.y - p1.y) * (X_MIN - p1.x) / (p2.x - p1.x);
    } else if (edge == RIGHT) {
        intersection.x = X_MAX;
        intersection.y = p1.y + (p2.y - p1.y) * (X_MAX - p1.x) / (p2.x - p1.x);
    } else if (edge == BOTTOM) {
        intersection.x = p1.x + (p2.x - p1.x) * (Y_MIN - p1.y) / (p2.y - p1.y);
        intersection.y = Y_MIN;
    } else if (edge == TOP) {
        intersection.x = p1.x + (p2.x - p1.x) * (Y_MAX - p1.y) / (p2.y - p1.y);
        intersection.y = Y_MAX;
    }
    return intersection;
}

// Function to clip a polygon against a single edge of the window
int clipAgainstEdge(Point *inputPolygon, int numVertices, int edge, Point *outputPolygon) {
    int numOutputVertices = 0;
    Point S = inputPolygon[numVertices - 1];

    for (int i = 0; i < numVertices; i++) {
        Point P = inputPolygon[i];
        if ((edge & LEFT && P.x >= X_MIN) || (edge & RIGHT && P.x <= X_MAX) ||
            (edge & BOTTOM && P.y >= Y_MIN) || (edge & TOP && P.y <= Y_MAX)) {
            if ((edge == LEFT && S.x < X_MIN) || (edge == RIGHT && S.x > X_MAX) ||
                (edge == BOTTOM && S.y < Y_MIN) || (edge == TOP && S.y > Y_MAX)) {
                outputPolygon[numOutputVertices++] = calculateIntersection(S, P, edge);
            }
            outputPolygon[numOutputVertices++] = P;
        } else if ((edge == LEFT && S.x < X_MIN) || (edge == RIGHT && S.x > X_MAX) ||
                   (edge == BOTTOM && S.y < Y_MIN) || (edge == TOP && S.y > Y_MAX)) {
            outputPolygon[numOutputVertices++] = calculateIntersection(S, P, edge);
        }
        S = P;
    }
    return numOutputVertices;
}

// Function to perform polygon clipping using Sutherland-Hodgman algorithm
int sutherlandHodgman(Point *inputPolygon, int numVertices, Point *outputPolygon) {
    Point tempPolygon[MAX_POINTS];
    Point *input = inputPolygon;
    Point *output = outputPolygon;
    int numOutputVertices = numVertices;

    for (int edge = LEFT; edge <= TOP; edge <<= 1) {
        numOutputVertices = clipAgainstEdge(input, numOutputVertices, edge, tempPolygon);
        Point *temp = input;
        input = output;
        output = temp;
        if (numOutputVertices == 0)
            break;
    }
    return numOutputVertices;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Draw the clipping window
    drawWindow();

    // Define the input polygon
    Point inputPolygon[] = {{50, 150}, {200, 50}, {350, 150}, {350, 250}, {200, 350}, {50, 250}};
    int numVertices = sizeof(inputPolygon) / sizeof(inputPolygon[0]);

    // Draw the input polygon
    setcolor(WHITE);
    drawPolygon(inputPolygon, numVertices);

    // Define the output polygon (initialize with the input polygon)
    Point outputPolygon[MAX_POINTS];
    for (int i = 0; i < numVertices; i++) {
        outputPolygon[i] = inputPolygon[i];
    }

    // Perform polygon clipping using Sutherland-Hodgman algorithm
    int numOutputVertices = sutherlandHodgman(inputPolygon, numVertices, outputPolygon);

    // Draw the clipped polygon
    setcolor(YELLOW);
    drawPolygon(outputPolygon, numOutputVertices);

    delay(5000);
    closegraph();
    return 0;
}