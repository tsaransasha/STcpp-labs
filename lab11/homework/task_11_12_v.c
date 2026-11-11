#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NAME_LEN 50

typedef struct Toy {
    char name[NAME_LEN];
    double price;
    int age_min;
    int age_max;
} Toy;

bool input_toy(Toy* toy) {
    if (toy == NULL) {
        return false;
    }
    printf("Enter toy name: ");
    if (scanf(" %49[^\n]", toy->name) != 1) {
        return false;
    }
    printf("Enter price (UAH): ");
    if (scanf("%lf", &toy->price) != 1 || toy->price < 0) {
        return false;
    }
    printf("Enter age range (min max): ");
    if (scanf("%d %d", &toy->age_min, &toy->age_max) != 2) {
        return false;
    }
    if (toy->age_min > toy->age_max) {
        int temp = toy->age_min;
        toy->age_min = toy->age_max;
        toy->age_max = temp;
    }
    return true;
}

void print_toy(const Toy* toy) {
    printf("%s | %.2lf UAH | ages %d-%d\n", toy->name, toy->price, toy->age_min, toy->age_max);
}

bool write_toy_file(const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        return false;
    }
    int n;
    printf("Enter the number of toys: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fclose(file);
        return false;
    }
    for (int i = 0; i < n; i++) {
        Toy toy;
        if (!input_toy(&toy)) {
            fclose(file);
            return false;
        }
        fwrite(&toy, sizeof(Toy), 1, file);
    }
    fclose(file);
    return true;
}


static void output_name(FILE* out, const char* name) {
    char buf[NAME_LEN] = {0};
    strncpy(buf, name, NAME_LEN - 1);
    printf("  %s\n", name);
    fwrite(buf, NAME_LEN, 1, out);
}


int find_a(const char* filename, const char* result_file, double max_price) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return -1;
    }
    FILE* out = fopen(result_file, "wb");
    if (out == NULL) {
        fclose(file);
        return -1;
    }
    Toy toy;
    int count = 0;
    while (fread(&toy, sizeof(Toy), 1, file) == 1) {
        if (toy.price <= max_price && toy.age_min <= 5 && 5 <= toy.age_max) {
            output_name(out, toy.name);
            count++;
        }
    }
    fclose(file);
    fclose(out);
    return count;
}


int find_b(const char* filename, const char* result_file, int n, int m) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return -1;
    }
    FILE* out = fopen(result_file, "wb");
    if (out == NULL) {
        fclose(file);
        return -1;
    }
    Toy toy;
    int count = 0;
    while (fread(&toy, sizeof(Toy), 1, file) == 1) {
        bool fits_n = toy.age_min <= n && n <= toy.age_max;
        bool fits_m = toy.age_min <= m && m <= toy.age_max;
        if (fits_n && fits_m) {
            output_name(out, toy.name);
            count++;
        }
    }
    fclose(file);
    fclose(out);
    return count;
}

int find_c(const char* filename, const char* result_file, double a) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return -1;
    }
    Toy toy;
    double max_price = -1.0;
    while (fread(&toy, sizeof(Toy), 1, file) == 1) {
        if (toy.price > max_price) {
            max_price = toy.price;
        }
    }
    if (max_price < 0) {
        fclose(file);
        return 0;
    }

    FILE* out = fopen(result_file, "wb");
    if (out == NULL) {
        fclose(file);
        return -1;
    }
    rewind(file);
    int count = 0;
    while (fread(&toy, sizeof(Toy), 1, file) == 1) {
        if (max_price - toy.price <= a) {
            output_name(out, toy.name);
            count++;
        }
    }
    fclose(file);
    fclose(out);
    return count;
}

int main() {
    const char* filename = "toys.bin";

    if (!write_toy_file(filename)) {
        printf("Failed to write toys to file.\n");
        return 1;
    }

    double max_price;
    printf("\n(a) Enter max price: ");
    if (scanf("%lf", &max_price) == 1) {
        printf("Toys for 5-year-olds with price <= %.2lf:\n", max_price);
        int res = find_a(filename, "result_a.bin", max_price);
        if (res < 0) printf("Error.\n");
        else if (res == 0) printf("  None found.\n");
    }

    int n, m;
    printf("\n(b) Enter two ages n and m: ");
    if (scanf("%d %d", &n, &m) == 2) {
        printf("Toys for both %d and %d year-olds:\n", n, m);
        int res = find_b(filename, "result_b.bin", n, m);
        if (res < 0) printf("Error.\n");
        else if (res == 0) printf("  None found.\n");
    }

    double a;
    printf("\n(c) Enter a (max difference from the highest price): ");
    if (scanf("%lf", &a) == 1) {
        printf("Most expensive toys (within %.2lf UAH of max):\n", a);
        int res = find_c(filename, "result_c.bin", a);
        if (res < 0) printf("Error.\n");
        else if (res == 0) printf("  None found.\n");
    }

    return 0;
}