#include<iostream>
using namespace std;
const int N = 200010;
typedef long long LL;
const LL INF = -1e18,TINF = -1e17;
struct Node
{
    int l, r;
    LL z, zz, zzf, zzff, zff, ff, f, zf, zfz, fzf, zfzf, fz;
}tr[N * 4];
int a[N];
void pushup(int u)
{
    tr[u].z = max(tr[u << 1].z, tr[u << 1 | 1].z);

    tr[u].zz = max(tr[u << 1].z + tr[u << 1 | 1].z, max(tr[u << 1].zz, tr[u << 1 | 1].zz));
    if (tr[u].zz <= TINF)tr[u].zz = INF;

    tr[u].zzf = max(tr[u << 1].zzf, tr[u << 1 | 1].zzf);
    tr[u].zzf = max(tr[u].zzf, tr[u << 1].z + tr[u << 1 | 1].zf);
    tr[u].zzf = max(tr[u].zzf, tr[u << 1].zz + tr[u << 1 | 1].f);
    if (tr[u].zzf <= TINF)tr[u].zzf = INF;

    tr[u].zzff = max(tr[u << 1].zzff, tr[u << 1 | 1].zzff);
    tr[u].zzff = max(tr[u].zzff, tr[u << 1].z + tr[u << 1 | 1].zff);
    tr[u].zzff = max(tr[u].zzff, tr[u << 1].zz + tr[u << 1 | 1].ff);
    tr[u].zzff = max(tr[u].zzff, tr[u << 1].zzf + tr[u << 1 | 1].f);
    if (tr[u].zzff <= TINF)tr[u].zzff = INF;

    tr[u].zff = max(tr[u << 1].zff, tr[u << 1 | 1].zff);
    tr[u].zff = max(tr[u].zff, tr[u << 1].z + tr[u << 1 | 1].ff);
    tr[u].zff = max(tr[u].zff, tr[u << 1].zf + tr[u << 1 | 1].f);
    if (tr[u].zff <= TINF)tr[u].zff = INF;

    tr[u].ff = max(tr[u << 1].ff, tr[u << 1 | 1].ff);
    tr[u].ff = max(tr[u].ff, tr[u << 1].f + tr[u << 1 | 1].f);
    if (tr[u].ff <= TINF)tr[u].ff = INF;

    tr[u].f = max(tr[u << 1].f, tr[u << 1 | 1].f);

    tr[u].zf = max(tr[u << 1].zf, tr[u << 1 | 1].zf);
    tr[u].zf = max(tr[u].zf, tr[u << 1].z + tr[u << 1 | 1].f);
    if (tr[u].zf <= TINF)tr[u].zf = INF;

    tr[u].fz = max(tr[u << 1].fz, tr[u << 1 | 1].fz);
    tr[u].fz = max(tr[u].fz, tr[u << 1].f + tr[u << 1 | 1].z);
    if (tr[u].fz <= TINF)tr[u].fz = INF;

    tr[u].zfz = max(tr[u << 1].zfz, tr[u << 1 | 1].zfz);
    tr[u].zfz = max(tr[u].zfz, tr[u << 1].z + tr[u << 1 | 1].fz);
    tr[u].zfz = max(tr[u].zfz, tr[u << 1].zf + tr[u << 1 | 1].z);
    if (tr[u].zfz <= TINF)tr[u].zfz = INF;

    tr[u].fzf = max(tr[u << 1].fzf, tr[u << 1 | 1].fzf);
    tr[u].fzf = max(tr[u].fzf, tr[u << 1].f + tr[u << 1 | 1].zf);
    tr[u].fzf = max(tr[u].fzf, tr[u << 1].fz + tr[u << 1 | 1].f);
    if (tr[u].fzf <= TINF)tr[u].fzf = INF;

    tr[u].zfzf = max(tr[u << 1].zfzf, tr[u << 1 | 1].zfzf);
    tr[u].zfzf = max(tr[u].zfzf, tr[u << 1].z + tr[u << 1 | 1].fzf);
    tr[u].zfzf = max(tr[u].zfzf, tr[u << 1].zf + tr[u << 1 | 1].zf);
    tr[u].zfzf = max(tr[u].zfzf, tr[u << 1].zfz + tr[u << 1 | 1].f);
    if (tr[u].zfzf <= TINF)tr[u].zfzf = INF;
}
void build(int u, int l, int r)
{
    if (l == r)
    {
        tr[u].l = l;
        tr[u].r = r;
        tr[u].z = (long long)a[l] * a[l];
        tr[u].f = -(long long)a[l] * a[l];
        tr[u].ff = INF;
        tr[u].fzf = INF;
        tr[u].zf = INF;
        tr[u].zff = INF;
        tr[u].zfz = INF;
        tr[u].zfzf = INF;
        tr[u].zz = INF;
        tr[u].fz = INF;
        tr[u].zzf = INF;
        tr[u].zzff = INF;

    }
    else
    {
        tr[u] = { l,r };
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
    //printf("l: %d r: %d zfzf:%lld zzff:%lld zzf: %lld\n",l,r,tr[u].zfzf,tr[u].zzff,tr[u].zzf);
}
void pushup(Node& p1, Node& p2, Node& p3)
{
	
    p1.z = max(p2.z, p3.z);

    p1.zz = max(p2.z + p3.z, max(p2.zz, p3.zz));
    if (p1.zz <= TINF)p1.zz = INF;

    p1.zzf = max(p2.zzf, p3.zzf);
    p1.zzf = max(p1.zzf, p2.z + p3.zf);
    p1.zzf = max(p1.zzf, p2.zz + p3.f);
    if (p1.zzf <= TINF)p1.zzf = INF;

    p1.zzff = max(p2.zzff, p3.zzff);
    p1.zzff = max(p1.zzff, p2.z + p3.zff);
    p1.zzff = max(p1.zzff, p2.zz + p3.ff);
    p1.zzff = max(p1.zzff, p2.zzf + p3.f);
    if (p1.zzff <= TINF)p1.zzff = INF;

    p1.zff = max(p2.zff, p3.zff);
    p1.zff = max(p1.zff, p2.z + p3.ff);
    p1.zff = max(p1.zff, p2.zf + p3.f);
    if (p1.zff <= TINF)p1.zff = INF;

    p1.ff = max(p2.ff, p3.ff);
    p1.ff = max(p1.ff, p2.f + p3.f);
    if (p1.ff <= TINF)p1.ff = INF;

    p1.f = max(p2.f, p3.f);

    p1.zf = max(p2.zf, p3.zf);
    p1.zf = max(p1.zf, p2.z + p3.f);
    if (p1.zf <= TINF)p1.zf = INF;

    p1.fz = max(p2.fz, p3.fz);
    p1.fz = max(p1.fz, p2.f + p3.z);
    if (p1.fz <= TINF)p1.fz = INF;

    p1.zfz = max(p2.zfz, p3.zfz);
    p1.zfz = max(p1.zfz, p2.z + p3.fz);
    p1.zfz = max(p1.zfz, p2.zf + p3.z);
    if (p1.zfz <= TINF)p1.zfz = INF;

    p1.fzf = max(p2.fzf, p3.fzf);
    p1.fzf = max(p1.fzf, p2.f + p3.zf);
    p1.fzf = max(p1.fzf, p2.fz + p3.f);
    if (p1.fzf <= TINF)p1.fzf = INF;

    p1.zfzf = max(p2.zfzf, p3.zfzf);
    p1.zfzf = max(p1.zfzf, p2.z + p3.fzf);
    p1.zfzf = max(p1.zfzf, p2.zf + p3.zf);
    p1.zfzf = max(p1.zfzf, p2.zfz + p3.f);
    if (p1.zfzf <= TINF)p1.zfzf = INF;
    //return p1;
}
Node query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)return tr[u];
    int mid = tr[u].l + tr[u].r >> 1;
    Node p1, p2 = { 0,0,INF,INF,INF,INF,INF,INF,INF ,INF ,INF ,INF ,INF ,INF },
             p3 = { 0,0,INF,INF,INF,INF,INF,INF,INF ,INF, INF, INF, INF, INF };

    if (l <= mid)p2 = query(u << 1, l, r);
    if (r > mid)p3 = query(u << 1 | 1, l, r);
    pushup(p1, p2, p3);
    //printf("l: %d r: %d zfzf:%lld zzff:%lld zzf: %lld zfz: %lld zf: %lld fz:%lld\n",l,r,p1.zfzf,p1.zzff,p1.zzf,p1.zfz,p1.zf,p1.fz);
    return p1;
}
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
    	int n,m;
    	cin >> n >> m;
    	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
    	build(1, 1, n);
    	while (m--)
    	{
        	int l, r;
        	scanf("%d%d", &l, &r);
        	Node t = query(1, l, r);
        	printf("%lld\n", max(t.zfzf, t.zzff));
    	}
    }
    return 0;
}
