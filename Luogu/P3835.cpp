
#include <bits/stdc++.h>
using namespace std;
// 可持久化平衡树
const int N = 5 * 1e5;
int Tot = 0, Cnt = 0;
struct Node {
    int Lson, Rson;
    int Size;
    int Rand;
    int Val;
} Tree[(N << 7) + 10];
int Root[N + 10];
int newNode(int v = 0) {
    Tree[++Tot].Val = v;
    Tree[Tot].Rand = rand();
    Tree[Tot].Size = 1;
    Tree[Tot].Lson = Tree[Tot].Rson = 0;
    return Tot;
}
int copyNode(int p) {
    int ret = newNode();
    Tree[ret] = Tree[p];
    return ret;
}
void pushUp(int p) {
    Tree[p].Size = 1;
    if(Tree[p].Lson)    Tree[p].Size += Tree[Tree[p].Lson].Size;
    if(Tree[p].Rson)    Tree[p].Size += Tree[Tree[p].Rson].Size;
}
void split(int p, int k, int& x, int& y) {
    if(!p) {
        x = y = 0;
        return;
    }
    if(Tree[p].Val <= k) {
        x = copyNode(p);
        split(Tree[x].Rson, k, Tree[x].Rson, y);
        pushUp(x);
    } else {
        y = copyNode(p);
        split(Tree[y].Lson, k, x, Tree[y].Lson);
        pushUp(y);
    }
}
int merge(int x, int y) {
    if(!x || !y)    return x | y;
    if(Tree[x].Rand < Tree[y].Rand) {
        int p = copyNode(x);
        Tree[p].Rson = merge(Tree[p].Rson, y);
        pushUp(p);
        return p;
    } else {
        int p = copyNode(y);
        Tree[p].Lson = merge(x, Tree[p].Lson);
        pushUp(p);
        return p;
    }
}

void insertNode(int& p, int x) {
    int a, b;
    split(p, x, a, b);
    p = merge(merge(a, newNode(x)), b);
}

void deleteNode(int& p, int x) {
    int a, b, c;
    split(p, x, a, b);
    split(a, x - 1, a, c);
    c = merge(Tree[c].Lson, Tree[c].Rson);
    p = merge(merge(a, c), b);
}

int getRankByNum(int& p, int x) {
    int a, b;
    split(p, x - 1, a, b);
    int ans = Tree[a].Size + 1;
    p = merge(a, b);
    return ans;
}

int getNumByRank(int p, int v) {
    if(v == Tree[Tree[p].Lson].Size + 1)    return Tree[p].Val;
    else if(v <= Tree[Tree[p].Lson].Size)   return getNumByRank(Tree[p].Lson, v);
    else return getNumByRank(Tree[p].Rson, v - Tree[Tree[p].Lson].Size - 1);
}

int getPre(int& p, int v) {
    int x, y, k, ans;
    split(p, v - 1, x, y);
    if(!x)  return -2147483647;
    k = Tree[x].Size;
    ans = getNumByRank(x, k);
    p = merge(x, y);
    return ans;
}

int getNxt(int& p, int v) {
    int x, y, k, ans;
    split(p, v, x, y);
    if(!y)  return 2147483647;
    ans = getNumByRank(y, 1);
    p = merge(x, y);
    return ans;
}

int main() {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int v, op, x, a, b, c;
    for(int i = 1; i <= n; ++i) {
        cin >> v >> op >> x;
        Root[++Cnt] = Root[v];
        if(op == 1) {
            insertNode(Root[Cnt], x);
        } else if(op == 2) {
            deleteNode(Root[Cnt], x);
        } else if(op == 3) {
            printf("%d\n", getRankByNum(Root[Cnt], x));
        } else if(op == 4) {
            printf("%d\n", getNumByRank(Root[Cnt], x));
        } else if(op == 5) {
            printf("%d\n", getPre(Root[Cnt], x));
        } else {
            printf("%d\n", getNxt(Root[Cnt], x));
        }
    }
    return 0;
}