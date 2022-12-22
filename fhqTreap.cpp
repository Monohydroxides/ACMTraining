#include <bits/stdc++.h>
using namespace std;

// fhq-Treap 平衡树, 可持久化文艺平衡树, 可持久化平衡树

// // 可持久化文艺平衡树
// const int N = 2e5;
// int Tot = 0, Cnt = 0;
// struct Node {
//     int Size, Tag, Rand;
//     int Lson, Rson;
//     long long Val, Sum;
// } Tree[(N << 7) + 10];
// int Root[N + 10];
// int newNode(long long v = 0) {
//     Tree[++Tot].Val = v;
//     Tree[Tot].Sum = v;
//     Tree[Tot].Rand = rand();
//     Tree[Tot].Size = 1;
//     Tree[Tot].Lson = Tree[Tot].Rson = Tree[Tot].Tag = 0;
//     return Tot;
// }
// int copyNode(int p) {
//     int ret = newNode();
//     Tree[ret] = Tree[p];
//     return ret;
// }
// void pushUp(int p) {
//     Tree[p].Size = Tree[Tree[p].Lson].Size + Tree[Tree[p].Rson].Size + 1;
//     Tree[p].Sum = Tree[Tree[p].Lson].Sum + Tree[Tree[p].Rson].Sum + Tree[p].Val;
// }
// void pushDown(int p) {
//     if(!Tree[p].Tag)    return;
//     if(Tree[p].Lson)    Tree[p].Lson = copyNode(Tree[p].Lson);
//     if(Tree[p].Rson)    Tree[p].Rson = copyNode(Tree[p].Rson);
//     swap(Tree[p].Lson, Tree[p].Rson);
//     if(Tree[p].Lson)    Tree[Tree[p].Lson].Tag ^= 1;
//     if(Tree[p].Rson)    Tree[Tree[p].Rson].Tag ^= 1;
//     Tree[p].Tag=0;
// }
// void split(int p, int k, int &x, int &y) {
//     if(!p) {
//         x = y = 0;
//         return;
//     }
//     pushDown(p);
//     if(Tree[Tree[p].Lson].Size < k) {
//         x = copyNode(p);
//         split(Tree[x].Rson, k - Tree[Tree[p].Lson].Size - 1, Tree[x].Rson, y);
//         pushUp(x);
//     } else {
//         y = copyNode(p);
//         split(Tree[y].Lson, k, x, Tree[y].Lson);
//         pushUp(y);
//     }
// }
// int merge(int x, int y) {
//     if(!x || !y)    return x | y;
//     pushDown(x), pushDown(y);
//     if(Tree[x].Rand < Tree[y].Rand) {
//         Tree[x].Rson = merge(Tree[x].Rson, y);
//         pushUp(x);
//         return x;
//     } else {
//         Tree[y].Lson = merge(x, Tree[y].Lson);
//         pushUp(y);
//         return y;
//     }
// }
// // op == 1: 在第 p 个数后插入数 x.
// // op == 2: 删除第 p 个数.
// // op == 3: 翻转区间 [l,r].
// // op == 4: 查询区间 [l,r] 中所有数的和.

// int main() {
//     int n;
//     std::cin >> n;

//     int v, op;
//     long long a, b;
//     int x, y, z;
//     long long lastans = 0;

//     while(n--) {
//         scanf("%d%d", &v, &op);
//         if(op == 1) {
//             scanf("%lld%lld", &a, &b);
// 			a ^= lastans, b ^= lastans;
// 			split(Root[v], a, x, y);
// 			Root[++Cnt] = merge(merge(x, newNode(b)), y);
//         } else if(op == 2) {
//             scanf("%lld", &a);
// 			a ^= lastans;
// 			split(Root[v], a, x, z);
// 			split(x, a - 1, x, y);
//             y = merge(Tree[y].Lson, Tree[y].Rson);
// 			Root[++Cnt] = merge(x, z);
//         } else if(op == 3) {
//             scanf("%lld%lld", &a, &b);
// 			a ^= lastans, b ^= lastans;
// 			split(Root[v], b, x, z);
// 			split(x, a - 1, x, y);
// 		    Tree[y].Tag ^= 1;
// 			Root[++Cnt] = merge(merge(x, y), z);
//         } else {
//             scanf("%lld%lld", &a, &b);
// 			a ^= lastans, b ^= lastans;
// 			split(Root[v], b, x, z);
// 			split(x, a - 1, x, y);
// 			printf("%lld\n", lastans = Tree[y].Sum);
// 			Root[++Cnt] = merge(merge(x, y), z);
//         }
//     }
//     return 0;
// }

// // 可持久化平衡树
// const int N = 5 * 1e5;
// int Tot = 0, Cnt = 0;
// struct Node {
//     int Lson, Rson;
//     int Size;
//     int Rand;
//     int Val;
// } Tree[(N << 7) + 10];
// int Root[N + 10];
// int newNode(int v = 0) {
//     Tree[++Tot].Val = v;
//     Tree[Tot].Rand = rand();
//     Tree[Tot].Size = 1;
//     Tree[Tot].Lson = Tree[Tot].Rson = 0;
//     return Tot;
// }
// int copyNode(int p) {
//     int ret = newNode();
//     Tree[ret] = Tree[p];
//     return ret;
// }
// void pushUp(int p) {
//     Tree[p].Size = 1;
//     if(Tree[p].Lson)    Tree[p].Size += Tree[Tree[p].Lson].Size;
//     if(Tree[p].Rson)    Tree[p].Size += Tree[Tree[p].Rson].Size;
// }
// void split(int p, int k, int& x, int& y) {
//     if(!p) {
//         x = y = 0;
//         return;
//     }
//     if(Tree[p].Val <= k) {
//         x = copyNode(p);
//         split(Tree[x].Rson, k, Tree[x].Rson, y);
//         pushUp(x);
//     } else {
//         y = copyNode(p);
//         split(Tree[y].Lson, k, x, Tree[y].Lson);
//         pushUp(y);
//     }
// }
// int merge(int x, int y) {
//     if(!x || !y)    return x | y;
//     if(Tree[x].Rand < Tree[y].Rand) {
//         int p = copyNode(x);
//         Tree[p].Rson = merge(Tree[p].Rson, y);
//         pushUp(p);
//         return p;
//     } else {
//         int p = copyNode(y);
//         Tree[p].Lson = merge(x, Tree[p].Lson);
//         pushUp(p);
//         return p;
//     }
// }

// void insertNode(int& p, int x) {
//     int a, b;
//     split(p, x, a, b);
//     p = merge(merge(a, newNode(x)), b);
// }

// void deleteNode(int& p, int x) {
//     int a, b, c;
//     split(p, x, a, b);
//     split(a, x - 1, a, c);
//     c = merge(Tree[c].Lson, Tree[c].Rson);
//     p = merge(merge(a, c), b);
// }

// int getRankByNum(int& p, int x) {
//     int a, b;
//     split(p, x - 1, a, b);
//     int ans = Tree[a].Size + 1;
//     p = merge(a, b);
//     return ans;
// }

// int getNumByRank(int p, int v) {
//     if(v == Tree[Tree[p].Lson].Size + 1)    return Tree[p].Val;
//     else if(v <= Tree[Tree[p].Lson].Size)   return getNumByRank(Tree[p].Lson, v);
//     else return getNumByRank(Tree[p].Rson, v - Tree[Tree[p].Lson].Size - 1);
// }

// int getPre(int& p, int v) {
//     int x, y, k, ans;
//     split(p, v - 1, x, y);
//     if(!x)  return -2147483647;
//     k = Tree[x].Size;
//     ans = getNumByRank(x, k);
//     p = merge(x, y);
//     return ans;
// }

// int getNxt(int& p, int v) {
//     int x, y, k, ans;
//     split(p, v, x, y);
//     if(!y)  return 2147483647;
//     ans = getNumByRank(y, 1);
//     p = merge(x, y);
//     return ans;
// }

// int main() {
//     cin.tie(0), cout.tie(0);
//     ios::sync_with_stdio(false);
//     int n;
//     cin >> n;
//     int v, op, x, a, b, c;
//     for(int i = 1; i <= n; ++i) {
//         cin >> v >> op >> x;
//         Root[++Cnt] = Root[v];
//         if(op == 1) {
//             insertNode(Root[Cnt], x);
//         } else if(op == 2) {
//             deleteNode(Root[Cnt], x);
//         } else if(op == 3) {
//             printf("%d\n", getRankByNum(Root[Cnt], x));
//         } else if(op == 4) {
//             printf("%d\n", getNumByRank(Root[Cnt], x));
//         } else if(op == 5) {
//             printf("%d\n", getPre(Root[Cnt], x));
//         } else {
//             printf("%d\n", getNxt(Root[Cnt], x));
//         }
//     }
//     return 0;
// }

// // 平衡树
// mt19937 rnd(666);
// const int N = 5 * 1e5;
// int Tot = 0;
// struct Node {
//     int Lson, Rson;
//     int Size;
//     int Rand;
//     int Val;
// } Tree[N << 1];
// int Root = 0;
// int newNode(int v = 0) {
//     Tree[++Tot].Val = v;
//     Tree[Tot].Rand = rnd();
//     Tree[Tot].Size = 1;
//     Tree[Tot].Lson = Tree[Tot].Rson = 0;
//     return Tot;
// }
// int copyNode(int p) {
//     int ret = newNode();
//     Tree[ret] = Tree[p];
//     return ret;
// }
// void pushUp(int p) {
//     Tree[p].Size = 1;
//     if(Tree[p].Lson)    Tree[p].Size += Tree[Tree[p].Lson].Size;
//     if(Tree[p].Rson)    Tree[p].Size += Tree[Tree[p].Rson].Size;
// }
// void split(int p, int k, int& x, int& y) {
//     if(!p) {
//         x = y = 0;
//         return;
//     }
//     if(Tree[p].Val <= k) {
//         x = p;
//         split(Tree[p].Rson, k, Tree[p].Rson, y);
//         pushUp(p);
//     } else {
//         y = p;
//         split(Tree[p].Lson, k, x, Tree[p].Lson);
//         pushUp(p);
//     }
// }
// int merge(int x, int y) {
//     if(!x || !y)    return x | y;
//     if(Tree[x].Rand < Tree[y].Rand) {
//         Tree[x].Rson = merge(Tree[x].Rson, y);
//         pushUp(x);
//         return x;
//     } else {
//         Tree[y].Lson = merge(x, Tree[y].Lson);
//         pushUp(y);
//         return y;
//     }
// }

// void insertNode(int& p, int x) {
//     int a, b;
//     split(p, x, a, b);
//     p = merge(merge(a, newNode(x)), b);
// }

// void deleteNode(int& p, int x) {
//     int a, b, c;
//     split(p, x, a, b);
//     split(a, x - 1, a, c);
//     c = merge(Tree[c].Lson, Tree[c].Rson);
//     p = merge(merge(a, c), b);
// }

// int getRankByNum(int& p, int x) {
//     int a, b;
//     split(p, x - 1, a, b);
//     int ans = Tree[a].Size + 1;
//     p = merge(a, b);
//     return ans;
// }

// int getNumByRank(int p, int v) {
//     while (1) {
//         if (v <= Tree[Tree[p].Lson].Size) {
//             p = Tree[p].Lson;
//         } else if (v == Tree[Tree[p].Lson].Size + 1) {
//             return Tree[p].Val;
//         } else {
//             v -= Tree[Tree[p].Lson].Size + 1;
//             p = Tree[p].Rson;
//         }
//     }
// }

// int getPre(int& p, int v) {
//     int x, y, k, ans;
//     split(p, v - 1, x, y);
//     if(!x)  return -2147483647;
//     k = Tree[x].Size;
//     ans = getNumByRank(x, k);
//     p = merge(x, y);
//     return ans;
// }

// int getNxt(int& p, int v) {
//     int x, y, k, ans;
//     split(p, v, x, y);
//     if(!y)  return 2147483647;
//     ans = getNumByRank(y, 1);
//     p = merge(x, y);
//     return ans;
// }

// int main() {
//     int n;
//     cin >> n;
//     for(int i = 1; i <= n; ++i) {
//         int op, x;
//         cin >> op >> x;
//         if(op == 1) {
//             insertNode(Root, x);
//         } else if(op == 2) {
//             deleteNode(Root, x);
//         } else if(op == 3) {
//             cout << getRankByNum(Root, x) << endl;
//         } else if(op == 4) {
//             cout << getNumByRank(Root, x) << endl;
//         } else if(op == 5) {
//             cout << getPre(Root, x) << endl; 
//         } else {
//             cout << getNxt(Root, x) << endl;
//         }
//     }
//     return 0;
// }