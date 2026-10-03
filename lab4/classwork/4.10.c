//
// Created by Олександра
//
#include <stdio.h>
#include <float.h>

int main() {
    float a = 1.0f;

    printf("Початкове значення a: %e\n", a);


    do {
        a /= 2.0f;
        printf("Поточне значення a: %e\n", a);
    } while (1.0f + (a / 2.0f) != 1.0f);

    printf("\nНайменше значення a, для якого 1 + a != 1: %e\n", a);
    printf("Машинний нуль (епсилон) з бібліотеки float.h (FLT_EPSILON): %e\n", FLT_EPSILON);

    return 0;
}