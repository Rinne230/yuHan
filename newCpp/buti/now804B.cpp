#include <bits/stdc++.h>
#define N 4009
using namespace std;
typedef long long ll;
const int mod = 998244353;
ll a[N], b[N], fac[N], inv[N];
int n;
ll power(ll x, ll y)
{
    ll ans = 1;
    while (y)
    {
        if (y & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}
ll C(int n, int m)
{
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
ll calc(int x, int y)
{
    if (x > y)
        swap(x, y);
    if (!x)
        return 1;
    return C(x + y, x);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    fac[0] = 1;
    for (int i = 1; i <= n * 2; ++i)
        fac[i] = fac[i - 1] * i % mod;
    inv[n * 2] = power(fac[n * 2], mod - 2);
    for (int i = 2 * n - 1; i >= 0; --i)
        inv[i] = inv[i + 1] * (i + 1) % mod;
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            (ans += abs(a[i] - b[j]) * calc(i - 1, j - 1) % mod * calc(n - i, n - j) % mod) %= mod;
    // calc(x, y)=C(x + y, x)
    cout << ans;
    return 0;
}
