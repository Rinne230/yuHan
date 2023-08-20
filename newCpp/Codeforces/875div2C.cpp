#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;

int n;

int dfs(int u, int fa, vector<vector<int>> &g, map<pair<int, int>, int> &mp)
{
    int ans = 0;
    for (auto p : g[u])
    {
        if (p == fa)
            continue;
        ans = max(ans, (mp[{fa, u}] > mp[{u, p}]) + dfs(p, u, g, mp));
    }
    return ans;
}

void solve()
{
    cin >> n;
    vector<vector<int>> g(n + 1, vector<int>());
    map<pair<int, int>, int> mp;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        mp[{u, v}] = i;
        mp[{v, u}] = i;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    for (auto p : g[1])
        ans = max(ans, dfs(p, 1, g, mp));
    cout << ans + 1 << endl;
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