#include <bits/stdc++.h>
using namespace std;

// 可持久化文艺平衡树
const int N = 2e5;
int Tot = 0, Cnt = 0;
struct Node {
    int Size, Tag, Rand;
    int Lson, Rson;
    long long Val, Sum;
} Tree[(N << 7) + 10];
int Root[N + 10];
int newNode(long long v = 0) {
    Tree[++Tot].Val = v;
    Tree[Tot].Sum = v;
    Tree[Tot].Rand = rand();
    Tree[Tot].Size = 1;
    Tree[Tot].Lson = Tree[Tot].Rson = Tree[Tot].Tag = 0;
    return Tot;
}
int copyNode(int p) {
    int ret = newNode();
    Tree[ret] = Tree[p];
    return ret;
}
void pushUp(int p) {
    Tree[p].Size = Tree[Tree[p].Lson].Size + Tree[Tree[p].Rson].Size + 1;
    Tree[p].Sum = Tree[Tree[p].Lson].Sum + Tree[Tree[p].Rson].Sum + Tree[p].Val;
}
void pushDown(int p) {
    if(!Tree[p].Tag)    return;
    if(Tree[p].Lson)    Tree[p].Lson = copyNode(Tree[p].Lson);
    if(Tree[p].Rson)    Tree[p].Rson = copyNode(Tree[p].Rson);
    swap(Tree[p].Lson, Tree[p].Rson);
    if(Tree[p].Lson)    Tree[Tree[p].Lson].Tag ^= 1;
    if(Tree[p].Rson)    Tree[Tree[p].Rson].Tag ^= 1;
    Tree[p].Tag=0;
}
void split(int p, int k, int &x, int &y) {
    if(!p) {
        x = y = 0;
        return;
    }
    pushDown(p);
    if(Tree[Tree[p].Lson].Size < k) {
        x = copyNode(p);
        split(Tree[x].Rson, k - Tree[Tree[p].Lson].Size - 1, Tree[x].Rson, y);
        pushUp(x);
    } else {
        y = copyNode(p);
        split(Tree[y].Lson, k, x, Tree[y].Lson);
        pushUp(y);
    }
}
int merge(int x, int y) {
    if(!x || !y)    return x | y;
    pushDown(x), pushDown(y);
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
// op == 1: 在第 p 个数后插入数 x.
// op == 2: 删除第 p 个数.
// op == 3: 翻转区间 [l,r].
// op == 4: 查询区间 [l,r] 中所有数的和.

int main() {
    int n;
    std::cin >> n;

    int v, op;
    long long a, b;
    int x, y, z;
    long long lastans = 0;

    while(n--) {
        scanf("%d%d", &v, &op);
        if(op == 1) {
            scanf("%lld%lld", &a, &b);
			a ^= lastans, b ^= lastans;
			split(Root[v], a, x, y);
			Root[++Cnt] = merge(merge(x, newNode(b)), y);
        } else if(op == 2) {
            scanf("%lld", &a);
			a ^= lastans;
			split(Root[v], a, x, z);
			split(x, a - 1, x, y);
            y = merge(Tree[y].Lson, Tree[y].Rson);
			Root[++Cnt] = merge(x, z);
        } else if(op == 3) {
            scanf("%lld%lld", &a, &b);
			a ^= lastans, b ^= lastans;
			split(Root[v], b, x, z);
			split(x, a - 1, x, y);
		    Tree[y].Tag ^= 1;
			Root[++Cnt] = merge(merge(x, y), z);
        } else {
            scanf("%lld%lld", &a, &b);
			a ^= lastans, b ^= lastans;
			split(Root[v], b, x, z);
			split(x, a - 1, x, y);
			printf("%lld\n", lastans = Tree[y].Sum);
			Root[++Cnt] = merge(merge(x, y), z);
        }
    }
    return 0;
}