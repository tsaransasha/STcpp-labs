#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char city[50];
    char street[50];
    unsigned int building;
    unsigned int apartment;
} Address;

bool inputAddress(Address* a) {
    printf("Address (city street building apartment): ");
    if(scanf("%49s %49s %u %u", a->city, a->street, &a->building, &a->apartment) != 4) 
        return false;
    return true;
}

void printAddress(Address a) {
    printf("City: %s, St. %s, Bldg. %s, Apt. %u\n", a.city, a.street, a.building, a.apartment); // Примітка: для рядків використовується %s
}

int main() {
    Address a;
    if(!inputAddress(&a)) {
        printf("Invalid address\n");
        return 1;
    }
    printAddress(a);
    return 0;
}