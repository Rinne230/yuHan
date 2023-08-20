#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
int n, cnt = 0, head[maxn], nxt[maxn << 1], to[maxn << 1], val[maxn << 1], f[maxn], ans[maxn], d[maxn], res;

void solve()
{
    auto add = [&](int u, int v, int w)
    {
        nxt[++cnt] = head[u];
        to[cnt] = v;
        val[cnt] = w;
        head[u] = cnt;
    };
    function<void(int, int)> dfs1 = [&](int u, int fa)
    {
        f[u] = 0;
        for (int i = head[u]; ~i; i = nxt[i])
        {
            int v = to[i];
            if (v == fa)
                continue;
            dfs1(v, u);
            if (d[v] > 1)
                f[u] += min(f[v], val[i]);
            else
                f[u] += val[i];
        }
    };
    function<void(int, int)> dfs2 = [&](int u, int fa)
    {
        res = max(res, ans[u]);
        for (int i = head[u]; ~i; i = nxt[i])
        {
            int v = to[i];
            if (v == fa)
                continue;
            if (d[u] != 1)
                ans[v] = f[v] + min(val[i], ans[u] - min(val[i], f[v]));
            else
                ans[v] = f[v] + val[i];
            dfs2(v, u);
        }
    };
    cin >> n;
    for (int i = 1; i <= n; ++i)
        head[i] = -1, d[i] = 0;
    cnt = 0;
    for (int i = 1; i < n; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
        d[u]++, d[v]++;
    }
    dfs1(1, 0);
    ans[1] = f[1], res = 0;
    dfs2(1, 0);
    cout << res << endl;
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