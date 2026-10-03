#include <stdio.h>


unsigned long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    unsigned long long f0 = 0, f1 = 1, f = 0;
    for (int k = 2; k <= n; k++) {
        f = f0 + f1;
        f0 = f1;
        f1 = f;
    }
    return f;
}


int find_max_fib_not_exceeding(unsigned long long a) {
    if (a == 0) return 0;

    unsigned long long f0 = 0, f1 = 1, f = 1;
    int n = 1;

    while (f <= a) {
        f0 = f1;
        f1 = f;
        f = f0 + f1;
        n++;
    }
    return n - 1;
}


int find_min_fib_greater_than(unsigned long long a) {
    unsigned long long f0 = 0, f1 = 1, f = 0;
    int n = 0;

    while (f <= a) {
        f0 = f1;
        f1 = f;
        f = f0 + f1;
        n++;
    }
    return n;
}


unsigned long long sum_fib_under_1000() {
    unsigned long long f0 = 0, f1 = 1, f = 0;
    unsigned long long total_sum = 0;

    if (0 <= 1000) total_sum += 0;
    if (1 <= 1000) total_sum += 1;

    f = f0 + f1;
    while (f <= 1000) {
        total_sum += f;
        f0 = f1;
        f1 = f;
        f = f0 + f1;
    }
    return total_sum;
}

int main() {
    int choice;
    printf("Choose a Fibonacci task[cite: 10]:\n");
    printf("1 - Calculate F_n by index n (point a)\n");
    printf("2 - Index of the largest Fibonacci number not exceeding a (point b)\n");
    printf("3 - Index of the smallest Fibonacci number greater than a (point c)\n");
    printf("4 - Sum of all Fibonacci numbers not exceeding 1000 (point d)\n");
    printf("Your choice (1-4): ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input.\n");
        return -1;
    }

    if (choice == 1) {
        int n;
        printf("Enter index n: ");
        scanf("%d", &n);
        if (n < 0) {
            printf("Index cannot be negative.\n");
            return -1;
        }
        printf("F(%d) = %llu\n", n, fibonacci(n));
    }
    else if (choice == 2) {
        unsigned long long a;
        printf("Enter number a: ");
        scanf("%llu", &a);
        int n = find_max_fib_not_exceeding(a);
        printf("Index of the largest Fibonacci number not exceeding %llu is %d (value = %llu)\n", a, n, fibonacci(n));
    }
    else if (choice == 3) {
        unsigned long long a;
        printf("Enter number a: ");
        scanf("%llu", &a);
        int n = find_min_fib_greater_than(a);
        printf("Index of the smallest Fibonacci number greater than %llu is %d (value = %llu)\n", a, n, fibonacci(n));
    }
    else if (choice == 4) {
        unsigned long long sum = sum_fib_under_1000();
        printf("Sum of all Fibonacci numbers not exceeding 1000 = %llu\n", sum);
    }
    else {
        printf("Invalid choice.\n");
    }

    return 0;
}