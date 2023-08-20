#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e3 + 10;
const int mod = 1000000007;
typedef long long ll;
vector<int> G[maxn];
ll res[2010][10];
ll ans;
ll vis[maxn];

ll C(ll n, ll m)
{
    if (m == 0 || m == n)
        return 1;
    if (res[n][m] != 0)
        return res[n][m];
    return res[n][m] = (C(n - 1, m) + C(n - 1, m - 1)) % mod;
}

void bfs(int u)
{
    for (int i = 0; i < G[u].size(); ++i)
    {
        int v = G[u][i];
        for (int j = 0; j < G[v].size(); ++j)
        {
            if (G[v][j] == u) continue;
            vis[G[v][j]]++;
        }
    }
}

void solve()
{
    memset(G, 0, sizeof(G));
    vector<int> sixp;   
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        G[i].clear();
    ans = 0;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (G[i].size() >= 6)
            sixp.push_back(i);
    }
    for (int i = 0; i < sixp.size(); ++i)
    {
        ll cnt = 0;
        memset(vis, 0, sizeof vis);
        bfs(sixp[i]);
        for (int j = 1; j <= n; ++j)
        {
            if (vis[j] >= 4)
                ans = (ans + C(vis[j], 4)) % mod;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}