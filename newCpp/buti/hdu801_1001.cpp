#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define eps 1e-8
#define z(x) (abs((x)) <= eps) // is zero

struct P {
    ll x, y;
    P (ll x = 0, ll y = 0) : x(x), y(y) {}
    P operator + (const P &p) const {return {x + p.x, y + p.y};} 
    P operator - (const P &p) const {return {x - p.x, y - p.y};} 
    P operator - () const {return {-x, -y};}

    ll operator | (const P &p) const {return x * p.x + y * p.y;} // dot
    ll operator ^ (const P &p) const {return x * p.y - y * p.x;} // cross
    
    ll norm() const {return x * x + y * y;}
    double dis(const P &p) const {return sqrt(((*this) - p).norm());}
} zero;

double abs(const P &p) {return sqrt(p.norm());}

struct L {
    P p, v;
    L(const P &p = zero, const P &v = zero) : p(p), v(v) {}
    double dis(const P &a) const {return abs(v ^ (a - p)) / abs(v);} 
};

struct S {
    P a, b;
    double dis(const P &p) const {
        if (((p - a) | (b - a)) < -eps || ((p - b) | (a - b)) < -eps) 
            return min(abs(a - p), abs(b - p));
        return L{a, b - a}.dis(p);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    --m;
    vector<S> seg(m);
    cin >> seg[0].a.x >> seg[0].a.y;
    for (int i = 0; i < m; ++i) {
        if (i != 0) seg[i].a = seg[i - 1].b;
        cin >> seg[i].b.x >> seg[i].b.y;
    }
    for (int i = 1; i <= n; ++i) {
        P nw; cin >> nw.x >> nw. y;
        double ans = 1e18;
        for (auto s : seg) ans = min(ans, s.dis(nw));
        printf("%.4lf\n", ans);
    }
    return 0;
} 