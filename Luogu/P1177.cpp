#include <stdio.h>

#define kMax 100005
// heap[0]: -1 -> small, 1 -> big
int heap[kMax], top;

void Init(int type)
{
    top = 0;
    heap[0] = type;
}

void Swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void Push(int x)
{
    heap[++top] = x;
    int type = heap[0];
    for (int i  = top; (heap[i / 2] - heap[i]) * type < 0 && i != 1; i /= 2) {
        Swap(&heap[i / 2], &heap[i]);
    }
}

int Pop()
{
    --top;
    int ans = heap[1], type = heap[0];
    Swap(&heap[1], &heap[top + 1]);
    for (int i = 1, next; (next = i * 2) <= top; i = next) {
        next = (heap[next] - heap[next + 1]) * type > 0 || next == top? next: next + 1;
        if ((heap[i] - heap[next]) * type < 0) {
            Swap(&heap[i], &heap[next]);
        }
    }
    return ans;
}

int GetTop()
{
    return heap[1];
}

int main()
{
    int n;
    Init(1);
    scanf("%d", &n);
    for (int i = 1, tmp; i <= n; ++i) {
        scanf("%d", &tmp);
        Push(tmp);
    }
    for (int i = 1; i <= n; ++i) {
        Pop();
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d%c", heap[i], i < n? ' ': '\n');
    }
    return 0;
}