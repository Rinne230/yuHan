#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 5e3 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

vector<int> G[maxn], finalpath, temppath;
ll w[maxn][maxn], cnt[maxn], cap, n, sp, m;
int mnot = inf, mnbk = inf, mncost = inf;
bool vis[maxn];
void dfs(int u, int ot, int bk, int cost)
{
    vis[u] = 1;
    temppath.push_back(u);
    if (cost > mncost)
        return;
    if (u == sp)
    {
        if (cost < mncost)
        {
            finalpath = temppath;
            mncost = cost;
            mnot = ot;
            mnbk = bk;
        }
        else if (cost == mncost && ot < mnot)
        {
            finalpath = temppath;
            mncost = cost;
            mnot = ot;
            mnbk = bk;
            
        }else if (cost == mncost && ot == mnot && bk < mnbk){
            finalpath = temppath;
            mncost = cost;
            mnot = ot;
            mnbk = bk;
        }
        return;
    }
    for (auto v : G[u]){
        if (!vis[v]){
            if (cnt[v] + bk < cap / 2) dfs(v, ot + cap / 2 - cnt[v] - bk, 0, cost + w[u][v]);
            else dfs(v, ot, bk + cnt[v] - cap / 2, cost + w[u][v]);
            vis[v] = 0;
            temppath.pop_back();
        }
    }
}
void solve()
{
    cin >> cap >> n >> sp >> m;
    for (int i = 1; i <= n; ++i)
        cin >> cnt[i];
    for (int i = 1, u, v, c; i <= m; ++i)
    {
        cin >> u >> v >> c;
        G[u].push_back(v);
        G[v].push_back(u);
        w[u][v] = w[v][u] = c;
    }
    dfs(0, 0, 0, 0);
    cout << mnot << " ";
    for (int i = 0; i < finalpath.size(); ++i){
        if (i == finalpath.size() - 1) cout << finalpath[i] << " ";
        else cout << finalpath[i] << "->";
    }
    cout << mnbk << endl;
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