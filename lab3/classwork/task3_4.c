//
// Created by Олександра
//
#include <stdio.h>
#include <stdint.h>

uint16_t multiply_uint8(uint8_t a, uint8_t b) {
    return (uint16_t)a * (uint16_t)b;
}

int main() {
    unsigned int in_a, in_b;

    printf("Enter two 8-bit unsigned numbers: ");
    scanf("%u %u", &in_b, &in_b);

    uint8_t a = (uint8_t)in_a;
    uint8_t b = (uint8_t)in_b;

    uint16_t result = multiply_uint8(a, b);

    printf("Product (16-bit): %u\n", result);

    return 0;
}