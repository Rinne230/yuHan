#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define rep(i, j, k) for (int i = (j); i <= (k); i++)
#define per(i, j, k) for (int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 1001;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    vector<int> f(n + 1);
    vector<tll> t(n + 1);
    vector<int> G[maxn];
    vector<int> in(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        auto &[a, b, c] = t[i];
        cin >> a >> b >> c;
    }
    auto cmp = [&](auto x, auto y) -> int
    {
        auto &[r, b, g] = x;
        auto &[R, B, G] = y;
        return (r < R) && (g < G) && (b < B);
    };
    for (int i = 1; i <= n; ++i)
    {
        auto t1 = t[i];
        for (int j = 1; j <= n; ++j)
        {
            if (j == i)
                continue;
            auto t2 = t[j];
            if (cmp(t1, t2))
            {
                in[j]++;
                G[i].push_back(j);
            }
        }
    }
    function<void(int, int)> dfs = [&](int u, int cnt)
    {
        f[u] = max(cnt, f[u]);
        for (auto v : G[u])
        {
            if (f[v] >= cnt + 1)
                continue;
            dfs(v, cnt + 1);
        }
    };
    for (int i = 1; i <= n; ++i)
    {
        if (in[i] == 0)
        {
            dfs(i, 0);
        }
    }
    if (cmp(t[1], t[2]) || cmp(t[2], t[1]))
    {
        cout << "-1\n";
        return;
    }
    if (f[1] == f[2])
    {
        bool flag = true;
        for (int i = 1; i <= n; ++i)
        {
            if (f[i] > 255)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            rep(i, 1, n) cout << f[i] << endl;
            return;
        }
        else
        {
            cout << -1 << endl;
            return;
        }
    }
    int mx = max(f[1], f[2]);
    if (f[1] == mx)
    {
        dfs(2, mx);
    }
    else
    {
        dfs(1, mx);
    }
    bool flag = true;
    for (int i = 1; i <= n; ++i)
    {
        if (f[i] > 255)
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        rep(i, 1, n) cout << f[i] << endl;
        return;
    }
    else
    {
        cout << -1 << endl;
        return;
    }
}

int main()
{
    ios;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}