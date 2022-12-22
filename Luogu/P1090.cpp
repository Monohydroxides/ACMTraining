#include <malloc.h>
#include <stdio.h>
#include <string.h>
#define Elem int
#define DEFAULT_CAPACITY 2
typedef struct heap {
    int size;
    int capacity;
    int big;
    Elem *data;
} Heap;
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
    a->data = (Elem *)malloc(sizeof(Elem) * DEFAULT_CAPACITY);
}
void heap_expand(Heap *a) {
    a->capacity *= 2;
    Elem *t = (Elem *)malloc(sizeof(Elem) * a->capacity);
    for (int i = 1; i <= a->size; ++i) {
        t[i] = a->data[i];
    }
    free(a->data);
    a->data = t;
    return;
}
int heap_isempty(Heap *a) { return !(a->size); }
Elem heap_top(Heap *a) {
    if (!heap_isempty(a))
        return a->data[1];
    return -1;
}
void heap_insert(Heap *a, Elem dat) {
    if (a->size * 2 >= a->capacity) {
        heap_expand(a);
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
    long long ans = 0;
    int n;
    scanf("%d", &n);
    Heap *a = (Heap *)malloc(sizeof(Heap));
    heap_init(a, 0);
    for (int i = 1; i <= n; ++i) {
        long long temp;
        scanf("%lld", &temp);
        heap_insert(a, temp);
    }
    while (a->size != 1) {
        long long a1 = heap_pop(a), a2 = heap_pop(a);
        ans += a1 + a2;
        heap_insert(a, a1 + a2);
    }
    printf("%lld", ans);
    return 0;
}