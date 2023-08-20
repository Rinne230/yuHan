#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define rep(i, j, k) for (int i = (j); i <= (k); i++)
#define per(i, j, k) for (int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 303;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;

void add(int &x, int y)
{
    x += y;
    if (x >= mod)
        x -= mod;
}

int n, t, K, m, ans = 0;
int sum[maxn], num[maxn], f[maxn][1 << 11][15]; // f[i][j][k] 表示在前 i 分钟，最近 K 分钟内的提交状态为 j 并且总共提交了 k 个答案的方案数

void solve()
{
    cin >> n >> t >> K >> m;
    for (int i = 0, x; i < n; ++i)
        cin >> x, num[x]++;
    for (int i = 1; i <= t; ++i)
        sum[i] = sum[i - 1] + num[i];
    f[0][0][0] = 1;
    for (int i = 0; i < t; ++i)
        for (int j = 0; j < 1 << K; ++j)
        {
            int p = __builtin_popcount(j);
            if (p > m)
                continue;
            for (int k = 0; k <= sum[i + 1]; ++k)
            {
                add(f[i + 1][j >> 1][k], f[i][j][k]);
                if (__builtin_popcount(j >> 1) + 1 <= m)
                    add(f[i + 1][(j >> 1) | (1 << (K - 1))][k + 1], 1ll * f[i][j][k] * (sum[i + 1] - k) % mod);
            }
        }
    for (int i = 0; i < 1 << K; ++i)
        add(ans, f[t][i][n]);
    cout << ans << endl;
}

int main()
{
    ios;
    solve();
    return 0;
}