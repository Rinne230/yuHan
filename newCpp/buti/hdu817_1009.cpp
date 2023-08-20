#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define rep(i, j, k) for (int i = (j); i <= (k); i++)
#define per(i, j, k) for (int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;
const int max_n = 1e5, max_gc = 5e5;
vector<int> c[max_n];
int p[max_n], ord[max_n], lst[max_gc];
pair<double, int> s[max_gc * 2];

inline void chmin(double &_a, double _b)
{
    if (_a > _b)
        _a = _b;
}

void solve()
{
    int n, cl;
    cin >> n >> cl;
    for (int i = 0, m; i < n; ++i)
    {
        cin >> p[i] >> m;
        c[i].clear();
        for (int j = 0, x; j < m; ++j)
        {
            cin >> x;
            x--;
            c[i].push_back(x);
        }
    }
    iota(ord, ord + n, 0);
    sort(ord, ord + n, [&](int x, int y)
         { return p[x] < p[y]; });
    fill(lst, lst + cl, -1);
    double curv = 0;
    int sc = 0;
    for (int _i = 0; _i < n; _i++)
    {
        int i = ord[_i];
        for (auto x : c[i])
        {
            if (lst[x] != -1)
                s[sc++] = make_pair((lst[x] + p[i]) / 2., -2);
            else
                curv += p[i];
            s[sc++] = make_pair(p[i], 2);
            lst[x] = p[i];
        }
    }
    sort(s, s + sc);

    double ans = curv, cx = 0;
    int slp = -cl;

    for (int i = 0; i < sc; i++)
    {
        auto [ps, d] = s[i];
        curv += slp * (ps - cx);
        cx = ps;
        slp += d;
        chmin(ans, curv);
    }
    cout << ll(ans) << endl;
}

int main()
{
    ios;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}