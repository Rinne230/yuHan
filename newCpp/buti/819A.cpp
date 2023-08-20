#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define rep(i, j, k) for (int i = (j); i <= (k); i++)
#define per(i, j, k) for (int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

int col[maxn];
int cost[maxn];
int dp[maxn];
vector<int> G[maxn];

int dfs(int u)
{
    vector<int> b, w;
    if (col[u] == 0)
        w.push_back(u);
    else
        b.push_back(u);
    for (auto v : G[u])
    {
        int idx = dfs(v);
        if (idx)
        {
            if (col[idx] == 0)
                w.push_back(idx);
            else
                b.push_back(idx);
        }
        dp[u] += dp[v];
    }
    sort(b.begin(), b.end(), [&](int x, int y)
         { return cost[x] < cost[y]; });
    sort(w.begin(), w.end(), [&](int x, int y)
         { return cost[x] < cost[y]; });
    while (!b.empty() && !w.empty())
        b.pop_back(), w.pop_back();
    int addanother = 0;
    while(!b.empty() && (int)b.size() - addanother > 1){
        dp[u] += cost[b.front()];
        addanother++;
        b.erase(b.begin());
    }
    while (!w.empty() && (int)w.size() - addanother > 1){
        dp[u] += cost[w.front()];
        addanother++;
        w.erase(w.begin());
    }
    if (!b.empty() && (int)b.size() - addanother > 0) return b[0];
    if (!w.empty() && (int)w.size() - addanother > 0) return w[0];
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int m;
        cin >> col[i] >> cost[i] >> m;
        while (m--)
        {
            int x;
            cin >> x;
            G[i].push_back(x);
        }
    }
    dfs(1);
    cout << dp[1] << endl;
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