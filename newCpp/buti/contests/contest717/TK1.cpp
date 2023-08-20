#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
vector<int> G[maxn];
int dep[maxn], pre[maxn], nxt[maxn], k;
bool vis[maxn];
queue<int> q;
ll ans = 0, ans1 = 0;

void bfs()
{
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 1;
        if (dep[u] <= k)
            ans++;
        for (int i = 0, v; i < G[u].size(); ++i)
        {
            v = G[u][i];
            if (!vis[v])
            {
                vis[v] = 1;
                dep[v] = dep[u] + 1;
                nxt[u] = v;
                pre[v] = u;
                q.push(v);
            }
        }
    }
    ans--;
}

void bfs_max()
{
    memset(vis, 0, sizeof(vis));
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 1;
        int maxdep = 0;
        for (int i = 0, v; i < G[u].size(); ++i)
        {
            v = G[u][i];
            if (!vis[v])
            {
                vis[v] = 1;
                q.push(v);
            }
            if (nxt[u] != v && pre[v] != u && k > dep[u])
            {                   
                if (u == 1 || v == 1) continue;
                cout << u << " " << v << ":" << k - dep[u] << endl;
                ans1 += k - dep[u];
            }
            if (dep[v] > maxdep)
                maxdep = dep[v];
        }

    }
    cout << ans << endl;
}

int main()
{
    ios;
    int n, m;
    cin >> n >> m >> k;
    if (m == 0)
    {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1, u, v; i <= m; ++i)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    q.push(1);
    bfs();
    q.push(1);
    bfs_max();
    // for (int i = 1; i <= n; ++i) cout << i << " : " << dep[i] << endl;
    return 0;
}