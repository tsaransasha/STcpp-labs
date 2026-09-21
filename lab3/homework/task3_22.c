//
// Created by Олександра 
//
#include <stdio.h>

int main() {
    double x, y, z;
    double height, radius;

    printf("Enter the coordinates of the point (x, y, z): ");
    scanf("%lf %lf %lf", &x, &y, &z);

    printf("Enter the cylinder height and base radius: ");
    scanf("%lf %lf", &height, &radius);

    if (z >= 0 && z <= height && (x * x + y * y <= radius * radius)) {
        printf("The point belongs to the cylinder.\n");
    } else {
        printf("The point does not belong to the cylinder.\n");
    }

    return 0;
}