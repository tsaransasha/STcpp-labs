//
// Created by Олександра
//
#include <stdio.h>

int maximum(int a, int b) {
    if (a > b) return a;
    return b;
}

int minimum(int a, int b) {
    return(a<b) ? a : b;
}
void task3_1_5() {
    int x, y;
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    printf("Max(%d, %d) = %d), Min(%d, %d) = %d\n", x, y, maximum(x, y), x, y, minimum(x, y));
}

int main() {
    task3_1_5();

}