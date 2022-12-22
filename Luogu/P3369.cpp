#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(666);
const int N = 5 * 1e5;
int Tot = 0;
struct Node {
    int Lson, Rson;
    int Size;
    int Rand;
    int Val;
} Tree[N << 1];
int Root = 0;
int newNode(int v = 0) {
    Tree[++Tot].Val = v;
    Tree[Tot].Rand = rnd();
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
        x = p;
        split(Tree[p].Rson, k, Tree[p].Rson, y);
        pushUp(p);
    } else {
        y = p;
        split(Tree[p].Lson, k, x, Tree[p].Lson);
        pushUp(p);
    }
}
int merge(int x, int y) {
    if(!x || !y)    return x | y;
    if(Tree[x].Rand < Tree[y].Rand) {
        Tree[x].Rson = merge(Tree[x].Rson, y);
        pushUp(x);
        return x;
    } else {
        Tree[y].Lson = merge(x, Tree[y].Lson);
        pushUp(y);
        return y;
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
    while (1) {
        if (v <= Tree[Tree[p].Lson].Size) {
            p = Tree[p].Lson;
        } else if (v == Tree[Tree[p].Lson].Size + 1) {
            return Tree[p].Val;
        } else {
            v -= Tree[Tree[p].Lson].Size + 1;
            p = Tree[p].Rson;
        }
    }
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
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int op, x;
        cin >> op >> x;
        if(op == 1) {
            insertNode(Root, x);
        } else if(op == 2) {
            deleteNode(Root, x);
        } else if(op == 3) {
            cout << getRankByNum(Root, x) << endl;
        } else if(op == 4) {
            cout << getNumByRank(Root, x) << endl;
        } else if(op == 5) {
            cout << getPre(Root, x) << endl; 
        } else {
            cout << getNxt(Root, x) << endl;
        }
    }
    return 0;
}