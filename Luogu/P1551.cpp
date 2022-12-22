#include <bits/stdc++.h>

using namespace std;

int parent[5001];

int find_root(int array[], int x)
{
    int x_root = x;
    if (array[x] != -1)
    {
        x_root = find_root(array, array[x]);
    }
    return x_root;
}

void union_relation(int x, int y, int array[])
{
    int x_root = find_root(array, x);
    int y_root = find_root(array, y);
    if (x_root == y_root)
    {
        return;
    }
    if (x_root < y_root)
    {
        array[y_root] = x_root;
    }
    else
    {
        array[x_root] = y_root;
    }
}

void initialize(int array[], int num)
{
    int i;
    for (i = 1; i <= num; i++)
    {
        array[i] = -1;
    }
}

void search(int x, int y, int array[])
{
    int x_root = find_root(array, x);
    int y_root = find_root(array, y);
    if (x_root == y_root)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}

int main()
{
    int i, j, k;
    int n, m, p;
    int relation1, relation2;
    scanf("%d %d %d", &n, &m, &p);
    initialize(parent, n);
    for (i = 1; i <= m; i++)
    {
        scanf("%d %d", &relation1, &relation2);
        union_relation(relation1, relation2, parent);
    }
    for (j = 1; j <= p; j++)
    {
        scanf("%d %d", &relation1, &relation2);
        search(relation1, relation2, parent);
    }
    return 0;
}