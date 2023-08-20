/***
 * Nazrin the Greeeeeedy Mouse
 */
#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const int N = 2e5 + 10, M = 205;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
int v[N], w[N];
int dp[M][M][M];
int f[N][M];
int n, m;
int sz[N];

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &v[i], &w[i]);
    }
    for (int i = 1; i <= m; i++)
        scanf("%d", &sz[i]);
    // dp[i][j][k]表示区间[i, j]用大小为k的包能获得的最大价值

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= M; j++)
            if (v[i] > j)
                dp[i][i][j] = 0;
            else
                dp[i][i][j] = w[i];
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = 0; k < M; k++)
            {
                dp[i][j][k] = dp[i][j - 1][k];
                if (k >= v[j])
                {
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - v[j]] + w[j]);
                }
            }
    // f[i][j]表示当前已经拿走/破坏到了第j个奶酪，并且进行到了第i个操作
    int mx = 0, num = 0;
    for (int i = m; i; i--)
    {
        for (int s = 1; s <= n; s++)  
        {
            for (int e = s; e <= n; e++)
            {
                f[i][s] = max(f[i][s], f[i + 1][e + 1] + dp[s][e][sz[i]]);
                mx = max(mx, f[i][s]);
            }
        }
        num++;
        if (num >= n)
            break;
    }
    cout << mx << endl;
}

int main()
{
    ios;
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}