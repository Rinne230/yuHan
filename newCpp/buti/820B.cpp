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

vector<int> ans;
int n, m;
bool vis[maxn];
vector<int> a(maxn);
vector<int> G[maxn];

void dfs(int u)
{
    if (u >= n - 1)
    {
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
        return;
    }
    for (int i = 0; i < m; ++i){
        if (!vis[i]){
            bool flag = true;
            for (int j = 0; j < G[i].size(); ++j){
                if (G[i][j] != a[u + j]){
                    flag = false;
                    break;
                }
            }
            if (flag){
                vis[i] = 1;
                ans.push_back(i);
                dfs(u + G[i].size() - 1);
                vis[i] = 0;
                ans.pop_back();
            }
        }
    }
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; ++j)
        {
            int num;
            cin >> num;
            G[i].push_back(num);
        }
    }
    dfs(0);
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