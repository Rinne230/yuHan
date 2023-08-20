#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 10;
const ll mod = 998244353;
int n;
int dis[maxn][maxn];
int f[1 << maxn];

void solve()
{
    while (cin >> n && n)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> dis[i][j];
        memset(f, 0, sizeof f);
        for (int sta = 0; sta < (1 << n); ++sta)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if ((sta >> i & 1) || (sta >> j & 1))
                        continue;
                    if (!(sta >> j & 1))
                        f[sta | (1 << j)] = max(f[sta | (1 << j)], f[sta] + dis[i][j]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, f[((1 << n) - 1) ^ (1 << i)]);
        cout << ans << endl;
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