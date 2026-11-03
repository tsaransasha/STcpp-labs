#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char fam[80];
    char town[80];
    char str[80];
    int bld;
    int apt;
} Person;

bool readPerson(Person* p) {
    printf("Surname city street house apartment (one-word names): ");
    return scanf("%79s%79s%79s%d%d", p->fam, p->town, p->str, &p->bld, &p->apt) == 5;
}

bool checkDiffTownsSameAddress(Person x, Person y) {
    return strcmp(x.town, y.town) != 0 &&
           strcmp(x.str, y.str) == 0 &&
           x.bld == y.bld &&
           x.apt == y.apt;
}

void showPerson(Person p) {
    printf("%s, %s, %s %d, apartment %d\n", p.fam, p.town, p.str, p.bld, p.apt);
}

int main() {
    int cnt;
    printf("Number of residents (2..10000): ");
    if(scanf("%d", &cnt) != 1 || cnt < 2 || cnt > 10000) return 1;

    Person* list = (Person*)malloc(cnt * sizeof(Person));
    if(!list) return 1;

    for(int i = 0; i < cnt; ++i) {
        if(!readPerson(&list[i])) {
            free(list);
            return 1;
        }
    }

    for(int i = 0; i < cnt; ++i) {
        for(int j = i + 1; j < cnt; ++j) {
            if(checkDiffTownsSameAddress(list[i], list[j])) {
                printf("Found two residents:\n");
                showPerson(list[i]);
                showPerson(list[j]);
                free(list);
                return 0;
            }
        }
    }

    printf("No such pair\n");
    free(list);
    return 0;
}