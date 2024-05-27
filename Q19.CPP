#include <stdio.h>

// Function to perform translation on a point
void translatePoint(int *x, int *y, int tx, int ty) {
    *x += tx;
    *y += ty;
}

int main() {
    int x = 10, y = 20; // Initial coordinates of the point
    int tx1 = 5, ty1 = 10; // First translation vector
    int tx2 = 15, ty2 = 20; // Second translation vector

    // Coordinates after first translation followed by second translation
    int x1 = x, y1 = y;
    translatePoint(&x1, &y1, tx1, ty1);
    translatePoint(&x1, &y1, tx2, ty2);

    // Coordinates after second translation followed by first translation
    int x2 = x, y2 = y;
    translatePoint(&x2, &y2, tx2, ty2);
    translatePoint(&x2, &y2, tx1, ty1);

    // Print results
    printf("Initial coordinates: (%d, %d)\n", x, y);
    printf("After first translation (tx1, ty1) and then (tx2, ty2): (%d, %d)\n", x1, y1);
    printf("After first translation (tx2, ty2) and then (tx1, ty1): (%d, %d)\n", x2, y2);

    // Verify if the two results are the same
    if (x1 == x2 && y1 == y2) {
        printf("Two successive translations are commutative in nature.\n");
    } else {
        printf("Two successive translations are not commutative in nature.\n");
    }

    return 0;
}