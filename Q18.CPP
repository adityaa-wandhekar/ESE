#include <stdio.h>
#include <math.h>
#include<conio.h>

#define PI 3.14159265

// Function to multiply two 2x2 matrices
void multiplyMatrices(float a[2][2], float b[2][2], float result[2][2]) {
    result[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    result[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    result[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    result[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
}

// Function to create a rotation matrix for a given angle
void createRotationMatrix(float angle, float matrix[2][2]) {
    float rad = angle * PI / 180;
    matrix[0][0] = cos(rad);
    matrix[0][1] = -sin(rad);
    matrix[1][0] = sin(rad);
    matrix[1][1] = cos(rad);
}

// Function to print a 2x2 matrix
void printMatrix(float matrix[2][2]) {
    printf("[[%f, %f],\n [%f, %f]]\n", matrix[0][0], matrix[0][1], matrix[1][0], matrix[1][1]);
}

int main() {
    clrscr();2
    float theta1, theta2;
    float R1[2][2], R2[2][2], R1R2[2][2], R2R1[2][2];

    // Define angles theta1 and theta2
    theta1 = 30.0;
    theta2 = 45.0;

    // Create rotation matrices R(theta1) and R(theta2)
    createRotationMatrix(theta1, R1);
    createRotationMatrix(theta2, R2);

    // Multiply R(theta1) and R(theta2)
    multiplyMatrices(R1, R2, R1R2);

    // Multiply R(theta2) and R(theta1)
    multiplyMatrices(R2, R1, R2R1);

    // Print matrices
    printf("R(theta1):\n");
    printMatrix(R1);

    printf("\nR(theta2):\n");
    printMatrix(R2);

    printf("\nR(theta1) * R(theta2):\n");
    printMatrix(R1R2);

    printf("\nR(theta2) * R(theta1):\n");
    printMatrix(R2R1);

    // Check if R(theta1) * R(theta2) equals R(theta2) * R(theta1)
    if (fabs(R1R2[0][0] - R2R1[0][0]) < 0.0001 &&
	fabs(R1R2[0][1] - R2R1[0][1]) < 0.0001 &&
	fabs(R1R2[1][0] - R2R1[1][0]) < 0.0001 &&
	fabs(R1R2[1][1] - R2R1[1][1]) < 0.0001) {
	printf("\nR(theta1) * R(theta2) is approximately equal to R(theta2) * R(theta1)\n");
    } else {
	printf("\nR(theta1) * R(theta2) is not equal to R(theta2) * R(theta1)\n");
    }
    getch();
    return 0;
}