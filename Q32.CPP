#include <graphics.h>
#include <stdlib.h>
#include <time.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define DISPLACEMENT_FACTOR 100 // Adjust this value to control the roughness of the coastline

// Function to generate random displacement
int randomDisplacement(int factor) {
    return rand() % factor - factor / 2;
}

// Function to draw a fractal coastline
void drawFractalCoastline(int x1, int y1, int x2, int y2, int iterations) {
    if (iterations == 0) {
        line(x1, y1, x2, y2);
        return;
    }

    int mid_x = (x1 + x2) / 2;
    int mid_y = (y1 + y2) / 2;

    int displacement = randomDisplacement(DISPLACEMENT_FACTOR);

    drawFractalCoastline(x1, y1, mid_x, mid_y + displacement, iterations - 1);
    drawFractalCoastline(mid_x, mid_y + displacement, x2, y2, iterations - 1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Seed the random number generator
    srand(time(NULL));

    // Set the initial points for coastline
    int x1 = 0, y1 = WINDOW_HEIGHT / 2;
    int x2 = WINDOW_WIDTH, y2 = WINDOW_HEIGHT / 2;

    // Set the number of iterations
    int iterations = 6;

    // Draw the fractal coastline
    drawFractalCoastline(x1, y1, x2, y2, iterations);

    delay(5000);
    closegraph();
    return 0;
}