#include <malloc.h>
#include <stdio.h>
#include <string.h>
#define Elem int
#define DEFAULT_CAPACITY 2000005
typedef struct heap {
    int size;
    int capacity;
    int big;
    Elem *data;
} Heap;

//
void swap(Elem *a, Elem *b) {
    Elem temp = *a;
    *a = *b;
    *b = temp;
    return;
}
void heap_up(Heap *a, int loc) {
    if (loc == 1) {
        return;
    }
    if (a->big) {
        if (a->data[loc] > a->data[loc / 2]) {
            swap(&a->data[loc], &a->data[loc / 2]);
            heap_up(a, loc / 2);
        }
    } else {
        if (a->data[loc] < a->data[loc / 2]) {
            swap(&a->data[loc], &a->data[loc / 2]);
            heap_up(a, loc / 2);
        }
    }
}
void heap_down(Heap *a, int loc) {
    if (loc * 2 > a->size) {
        return;
    }
    if (a->big) {
        if (loc * 2 + 1 > a->size) {
            if (a->data[loc] < a->data[loc * 2]) {
                swap(&a->data[loc], &a->data[loc * 2]);
                heap_down(a, loc * 2);
            }
        } else {
            if (a->data[loc * 2] > a->data[loc * 2 + 1]) {
                if (a->data[loc] < a->data[loc * 2]) {
                    swap(&a->data[loc], &a->data[loc * 2]);
                    heap_down(a, loc * 2);
                }
            } else {
                if (a->data[loc] < a->data[loc * 2 + 1]) {
                    swap(&a->data[loc], &a->data[loc * 2 + 1]);
                    heap_down(a, loc * 2 + 1);
                }
            }
        }
    } else {
        if (loc * 2 + 1 > a->size) {
            if (a->data[loc] > a->data[loc * 2]) {
                swap(&a->data[loc], &a->data[loc * 2]);
                heap_down(a, loc * 2);
            }
        } else {
            if (a->data[loc * 2] < a->data[loc * 2 + 1]) {
                if (a->data[loc] > a->data[loc * 2]) {
                    swap(&a->data[loc], &a->data[loc * 2]);
                    heap_down(a, loc * 2);
                }
            } else {
                if (a->data[loc] > a->data[loc * 2 + 1]) {
                    swap(&a->data[loc], &a->data[loc * 2 + 1]);
                    heap_down(a, loc * 2 + 1);
                }
            }
        }
    }
}
void heap_init(Heap *a, int big) {
    a->size = 0, a->capacity = DEFAULT_CAPACITY;
    a->big = big;
    a->data = (Elem *)malloc(sizeof(Heap) * DEFAULT_CAPACITY);
}
Heap *heap_expand(Heap *a) {
    Heap *b = (Heap *)malloc(sizeof(Heap));
    b->big = a->big;
    b->capacity = a->capacity * 2;
    b->size = a->size;
    b->data = (Elem *)malloc(sizeof(Heap) * b->capacity);
    for (int i = 1; i <= a->size; ++i) {
        b->data[i] = a->data[i];
    }
    return b;
}
int heap_isempty(Heap *a) { return !(a->size); }
Elem heap_top(Heap *a) {
    if (!heap_isempty(a))
        return a->data[1];
    return -1;
}
void heap_insert(Heap *a, Elem dat) {
    if (a->size * 2 > a->capacity) {
        a = heap_expand(a);
    }
    a->data[++a->size] = dat;
    heap_up(a, a->size);
    return;
}
Elem heap_pop(Heap *a) {
    if (heap_isempty(a)) {
        return -1;
    }
    Elem t = a->data[1];
    swap(&a->data[1], &a->data[a->size]);
    a->size--;
    heap_down(a, 1);
    return t;
}
int main() {
    // freopen("P3378_4.in", "r", stdin);
    // freopen("P3378_4.out", "w", stdout);
    Heap *a = (Heap *)malloc(sizeof(Heap));
    heap_init(a, 0);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int opt;
        scanf("%d", &opt);
        switch (opt) {
        case 1: {
            int num;
            scanf("%d", &num);
            heap_insert(a, num);
            break;
        }
        case 2: {
            printf("%d\n", heap_top(a));
            break;
        }
        case 3: {
            heap_pop(a);
        }
        }
    }
    return 0;
}
/*
15
1 2
1 5
1 8
1 -12
3
3
1 15
1 18
3
3
1 9
1 12
1 -2
3
1 17
*/