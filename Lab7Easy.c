//
// Created by viacheslav on 20.11.17.
// Линейный однонаправленный список
//
//
//

#include <stdio.h>
#include <stdlib.h>

struct Item {
    int a;
    struct Item *next;
};

struct Item *InputList() {
    struct Item *head, *cur, *tmp;
    int n;
    printf("Введите кол-во элементов списка:\n");
    scanf("%d", &n);
    if (n <= 0) return NULL;
    head = NULL;
    while (n-- > 0) {
        tmp = malloc(sizeof(struct Item));
        printf("Введите элемент:\n");
        scanf("%d", &tmp->a);
        if (head == NULL)
            head = cur = tmp;
        else
            cur->next = tmp;
        cur = tmp;
    }
    cur->next = NULL;
    return head;
};

void PrintList(struct Item *p, int n) {
    int i;
    for (i = 0; p; p = p->next, i++) {
        printf("%d%c", p->a, p->next && i%n ? ' ' : '\n');
    }
}

void SortList(struct Item *p) {
    struct Item *i, *j, *k;
    int tmp;
    for (i = p; i && i->next; i = i->next) {
        for (k = i, j = i->next; j; j = j->next) {
            if (i->a < k->a) k = j;
            tmp = i->a;
            i->a = k->a;
            k->a = tmp;
        }
    }
}

void FreeList(struct Item *p) {
    struct Item *tmp;
    while(p) {
        tmp = p;
        p = p->next;
        free(tmp);
    }
}

int main() {
    struct Item *List;
    while (printf("Введите список:\n"), List = InputList()) {
        printf("Исходный список\n");
        PrintList(List, 10);
        SortList(List);
        printf("Результат:\n");
        PrintList(List, 10);
        FreeList(List);
    }
    return 0;
}
