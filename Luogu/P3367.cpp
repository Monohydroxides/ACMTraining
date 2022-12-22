#include <bits/stdc++.h>

using namespace std;

int parent[10001];

void initialize(int array[], int num)
{
    int i;
    for (i = 1; i <= num; i++)
    {
        array[i] = -1;
    }
}

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

void search(int x, int y, int array[])
{
    int x_root = find_root(array, x);
    int y_root = find_root(array, y);
    if (x_root == y_root)
    {
        printf("Y\n");
    }
    else
    {
        printf("N\n");
    }
}

int main()
{
    int i, j, k;
    int n, m;
    int opt, relation1, relation2;
    scanf("%d %d", &n, &m);
    initialize(parent, n);
    for (i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &opt, &relation1, &relation2);
        if (opt == 1)
        {
            union_relation(relation1, relation2, parent);
        }
        else
        {
            search(relation1, relation2, parent);
        }
    }
    return 0;
}