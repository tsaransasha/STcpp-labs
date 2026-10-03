//
// Created by Олександра
//
#include <stdio.h>
#include <math.h>
int main() {
    double a;
    double sum = 0.0;
    double prod = 1.0;
    int k = 0;

    do {

        printf("a[%d]= ", k);
        scanf("%lf", &a);

        if (a != 0.0) {
            sum += a;
            prod *= a;
            k++;
        }
    } while (a != 0.0);

    if (k != 0) {
        printf("\n--- Результати ---\n");
        printf("Сума введених чисел: %lf\n", sum);
        printf("Середнє арифметичне: %lf\n", sum / k);


        if (prod > 0) {
            double geom_mean = pow(prod, 1.0 / k);
            printf("Середнє геометричне: %lf\n", geom_mean);
        } else {
            printf("Середнє геометричне: неможливо обчислити (добуток від'ємний або нульовий у дійсних числах).\n");
        }
    } else {
        printf("Не було введено жодного числа (окрім нуля).\n");
    }

    return 0;
}