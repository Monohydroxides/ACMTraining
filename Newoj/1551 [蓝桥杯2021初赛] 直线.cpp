#include <bits/stdc++.h>
using namespace std;
#define N 502
#define X 21
#define Y 20
struct Point {int x, y;Point() {}Point(int _x, int _y) : x(_x), y(_y) {}
} a[N];
int cnt_point;
struct Line {double k, b;Line() {}Line(double _k, double _b) : k(_k), b(_b) {}bool operator<(const Line &y) const {if (k == y.k) {return b < y.b;}return k < y.k;}
};
set<Line> e;
void addedge(Point x, Point y) {if (x.x == y.x || x.y == y.y) return;double fm = (y.x - x.x) * 1.0;double k = (y.y - x.y) * 1.0 / fm;double b = (x.y * y.x - x.x * y.y) * 1.0 / fm;e.insert(Line(k, b));
}
int main() {for (int x = 0; x < X; ++x) {for (int y = 0; y < Y; ++y) {a[cnt_point++] = Point(x, y);}}for (int i = 0; i < cnt_point; ++i) {for (int j = 0; j < cnt_point; ++j) {addedge(a[i], a[j]);}}cout << e.size() + X + Y << endl;return 0;
}