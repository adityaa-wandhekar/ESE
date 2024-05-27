#include <stdio.h>
#include <math.h>

#define PI 3.14159265

// Function to reflect a point about the X-axis
void reflectX(int *x, int *y) {
    *y = -*y;
}

// Function to rotate a point anticlockwise by 90 degrees
void rotate90(int *x, int *y) {
    int temp = *x;
    *x = -*y;
    *y = temp;
}

// Function to reflect a point about the line Y = X
void reflectYX(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int x = 3, y = 4;  // Initial coordinates of the point
    int rx, ry;        // Coordinates after reflection about Y = X
    int tempX, tempY;  // Temporary coordinates for intermediate transformations

    // Reflect about Y = X
    rx = x;
    ry = y;
    reflectYX(&rx, &ry);

    // Reflect relative to X-axis followed by anticlockwise rotation of 90 degrees
    tempX = x;
    tempY = y;
    reflectX(&tempX, &tempY);
    rotate90(&tempX, &tempY);

    // Print results
    printf("Initial coordinates: (%d, %d)\n", x, y);
    printf("After reflection about Y = X: (%d, %d)\n", rx, ry);
    printf("After reflection relative to X-axis followed by rotation of 90 degrees: (%d, %d)\n", tempX, tempY);

    // Verify if the two results are the same
    if (rx == tempX && ry == tempY) {
        printf("Reflection about Y = X is equivalent to reflection relative to X-axis followed by rotation of 90 degrees.\n");
    } else {
        printf("Reflection about Y = X is not equivalent to reflection relative to X-axis followed by rotation of 90 degrees.\n");
    }

    return 0;
}