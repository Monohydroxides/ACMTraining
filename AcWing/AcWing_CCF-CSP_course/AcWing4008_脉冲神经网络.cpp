#pragma GCC optimize(3)
#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int n, s, p, T, mod;
double dt;

int vid;
struct neuron {
    double a, b, c, d;
    double u, v;
    int sed;
} neu[1010];

int src[1010];

int to[2010], dlay[2010], head[2010], nxt[2010], eid;
double wv[2010];

void add (int a, int b, int c, double f) {
    dlay[eid] = c, wv[eid] = f, to[eid] = b, nxt[eid] = head[a], head[a] = eid++;
}

double ik[1010][1010];

static unsigned long nt = 1;
/* RAND_MAX assumed to be 32767 */
int myrand(void) {
    nt = nt * 1103515245 + 12345;
    return((unsigned)(nt/65536) % 32768);
}

void src_spread (int t) {
    for (int i = 1; i <= p; i++) {
        int cur = myrand();
        if (src[i] > cur) {
            for (int j = head[i + n - 1]; ~j; j = nxt[j]) {
                ik[(t + dlay[j]) % mod][to[j]] += wv[j];
            }
        }
    }   
}

void ner_spread (int t) {
    for (int i = 0; i < n; i++) {
        double lasv = neu[i].v, lasu = neu[i].u;
        neu[i].v = lasv + dt * (0.04 * lasv * lasv + 5 * lasv + 140 - lasu) + ik[t][i];
        neu[i].u = lasu + dt * neu[i].a * (neu[i].b * lasv - lasu);
        if (neu[i].v >= 30) {
            for (int j = head[i]; ~j; j = nxt[j]) {
                ik[(t + dlay[j]) % mod][to[j]] += wv[j];
            }
            neu[i].sed++;
            neu[i].v = neu[i].c;
            neu[i].u = neu[i].u + neu[i].d;
        }
    }
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> s >> p >> T;
    cin >> dt;
    memset(head, -1, sizeof head);
    while (vid < n) {
        int rn;
        double v, u, a, b, c, d;
        cin >> rn >> v >> u >> a >> b >> c >> d;
        for (int i = 1; i <= rn; i++) {
            neu[vid++] = {a, b, c, d, u, v, 0};
        }
    }
    for (int i = 1; i <= p; i++) {
        cin >> src[i];
    }
    for (int i = 1; i <= s; i++) {
        int fr, fs, dg;
        double w;
        cin >> fr >> fs >> w >> dg;
        add(fr, fs, dg, w);
        mod = max(mod, dg + 1);
    }

    for (int i = 1; i <= T; i++) {
        int t = i % mod;
        src_spread(t);
        ner_spread(t);
        memset(ik[t], 0, sizeof ik[t]);
    }

    double minans = 1e18, maxans = -1e18;
    int minsed = 1e9, maxsed = -1;
    for (int i = 0; i < n; i++) {
        minans = min(minans, neu[i].v);
        maxans = max(maxans, neu[i].v);
        maxsed = max(maxsed, neu[i].sed);
        minsed = min(minsed, neu[i].sed);
    }
    cout << fixed << setprecision(3) << minans << " " << maxans << "\n";
    cout << minsed << " " << maxsed << "\n";
    return 0;
} 