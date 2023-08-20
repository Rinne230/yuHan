#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 10;
const ll mod = 1000000007;
int fac[maxn], ifac[maxn], deg[maxn], ans[maxn];

int C(int n, int m)
{
    if (n < m)
        return 0;
    return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

int fpow(int x, int t = mod - 2)
{
    int res = 1;
    for (; t; t >>= 1, x = 1ll * x * x % mod)
        if (t & 1)
            res = 1ll * res * x % mod;
    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        deg[i] = ans[i] = 0;
    for (int i = 1; i <= m; ++i)
    {
        int x;
        cin >> x;
        ++deg[x];
        cin >> x;
        ++deg[x];
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 2; j <= deg[i]; ++j)
            ans[j] = (ans[j] + C(deg[i], j)) % mod;
    int res = 0;
    for (int i = 2; i <= n; ++i)
        res ^= ans[i];
    printf("%d\n", res);
}

int main()
{
    ios;
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < maxn; ++i)
        fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[maxn - 1] = fpow(fac[maxn - 1]);
    for (int i = maxn - 2; i; --i)
        ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}