#include <graphics.h>
#include <stdio.h>

#define MAX_VERTICES 20

// Define a structure to represent a point
typedef struct {
    int x, y;
} Point;

// Define a structure to represent a vertex of a polygon
typedef struct {
    Point point;
    int inside;
} Vertex;

// Function to draw a polygon
void drawPolygon(Vertex *polygon, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        int j = (i + 1) % numVertices;
        line(polygon[i].point.x, polygon[i].point.y, polygon[j].point.x, polygon[j].point.y);
    }
}

// Function to check if a point is inside a polygon
int insidePolygon(Point point, Vertex *polygon, int numVertices) {
    int crossings = 0;
    for (int i = 0; i < numVertices; i++) {
        int j = (i + 1) % numVertices;
        if ((polygon[i].point.y <= point.y && point.y < polygon[j].point.y) ||
            (polygon[j].point.y <= point.y && point.y < polygon[i].point.y)) {
            double intersection = (point.y - polygon[i].point.y) *
                                  (polygon[j].point.x - polygon[i].point.x) /
                                  (polygon[j].point.y - polygon[i].point.y) + polygon[i].point.x;
            if (point.x < intersection)
                crossings++;
        }
    }
    return (crossings % 2) == 1;
}

// Function to compute the intersection point of two line segments
Point intersectionPoint(Point p1, Point p2, Point q1, Point q2) {
    Point intersection;
    double s1_x = p2.x - p1.x;
    double s1_y = p2.y - p1.y;
    double s2_x = q2.x - q1.x;
    double s2_y = q2.y - q1.y;
    double s = (-s1_y * (p1.x - q1.x) + s1_x * (p1.y - q1.y)) / (-s2_x * s1_y + s1_x * s2_y);
    intersection.x = q1.x + (s2_x * s);
    intersection.y = q1.y + (s2_y * s);
    return intersection;
}

// Function to clip a subject polygon against a clipping polygon using Weiler-Atherton algorithm
void weilerAtherton(Vertex *subjectPolygon, int numSubjectVertices, Vertex *clippingPolygon, int numClippingVertices) {
    // Find intersection points and mark vertices as entering or exiting
    for (int i = 0; i < numSubjectVertices; i++) {
        int j = (i + 1) % numSubjectVertices;
        for (int k = 0; k < numClippingVertices; k++) {
            int l = (k + 1) % numClippingVertices;
            if ((subjectPolygon[i].inside && !clippingPolygon[k].inside) ||
                (!subjectPolygon[i].inside && clippingPolygon[k].inside)) {
                Point intersection = intersectionPoint(subjectPolygon[i].point, subjectPolygon[j].point,
                                                        clippingPolygon[k].point, clippingPolygon[l].point);
                Vertex vertex;
                vertex.point = intersection;
                vertex.inside = clippingPolygon[k].inside;
                clippingPolygon[k].inside ? numClippingVertices++ : numSubjectVertices++;
                for (int m = numSubjectVertices - 1; m > i; m--)
                    subjectPolygon[m] = subjectPolygon[m - 1];
                for (int m = numClippingVertices - 1; m > k; m--)
                    clippingPolygon[m] = clippingPolygon[m - 1];
                subjectPolygon[i + 1] = vertex;
                clippingPolygon[k + 1] = vertex;
            }
        }
    }

    // Output clipped polygon
    for (int i = 0; i < numSubjectVertices; i++) {
        if (subjectPolygon[i].inside) {
            setcolor(YELLOW);
            circle(subjectPolygon[i].point.x, subjectPolygon[i].point.y, 2);
            if (subjectPolygon[(i + 1) % numSubjectVertices].inside)
                line(subjectPolygon[i].point.x, subjectPolygon[i].point.y,
                     subjectPolygon[(i + 1) % numSubjectVertices].point.x,
                     subjectPolygon[(i + 1) % numSubjectVertices].point.y);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Define the subject polygon
    Vertex subjectPolygon[] = {{{150, 150}, 1}, {{250, 50}, 1}, {{350, 150}, 1}, {{350, 250}, 1}, {{250, 350}, 1}, {{150, 250}, 1}};
    int numSubjectVertices = sizeof(subjectPolygon) / sizeof(subjectPolygon[0]);

    // Define the clipping polygon
    Vertex clippingPolygon[] = {{{200, 200}, 1}, {{300, 100}, 1}, {{400, 200}, 1}, {{400, 300}, 1}, {{300, 400}, 1}, {{200, 300}, 1}};
    int numClippingVertices = sizeof(clippingPolygon) / sizeof(clippingPolygon[0]);

    // Draw the subject and clipping polygons
    setcolor(WHITE);
    drawPolygon(subjectPolygon, numSubjectVertices);
    drawPolygon(clippingPolygon, numClippingVertices);

    // Perform polygon clipping using Weiler-Atherton algorithm
    weilerAtherton(subjectPolygon, numSubjectVertices, clippingPolygon, numClippingVertices);

    delay(5000);
    closegraph();
    return 0;
}