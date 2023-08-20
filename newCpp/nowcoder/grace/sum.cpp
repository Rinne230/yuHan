#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 20010, mod = 998244353;
template <typename Tp>
inline int getmin(Tp &x, Tp y) { return y < x ? x = y, 1 : 0; }
template <typename Tp>
inline int getmax(Tp &x, Tp y) { return y > x ? x = y, 1 : 0; }
template <typename Tp>
inline void read(Tp &x)
{
    x = 0;
    int f = 0;
    char ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9'))
        ch = getchar();
    if (ch == '-')
        f = 1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    if (f)
        x = -x;
}
int n, m, p, nd = 1, pd = 1, ans, a[maxn], b[maxn], fac[maxn], inv[maxn];
int pls(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
int dec(int x, int y) { return x - y < 0 ? x - y + mod : x - y; }
int power(int x, int y)
{
    int res = 1;
    for (; y; y >>= 1, x = (ll)x * x % mod)
        if (y & 1)
            res = (ll)res * x % mod;
    return res;
}
int main()
{
    read(n);
    read(m);
    read(p);
    for (int i = 0; i <= m; i++)
        read(a[i]);
    fac[0] = 1;
    for (int i = 1; i <= m; i++)
        fac[i] = (ll)fac[i - 1] * i % mod;
    inv[m] = power(fac[m], mod - 2);
    for (int i = m - 1; ~i; i--)
        inv[i] = (ll)inv[i + 1] * (i + 1) % mod;
    for (int i = 0; i <= m; i++)
    {
        b[i] = (ll)a[0] * inv[i] % mod;
        for (int j = 0; j < m - i; j++)
            a[j] = dec(a[j + 1], a[j]);
    }
    for (int i = 0; i <= m; i++)
    {
        ans = pls(ans, (ll)b[i] * nd % mod * pd % mod);
        nd = (ll)nd * (n - i) % mod;
        pd = (ll)pd * p % mod;
    }
    printf("%d\n", ans);
    return 0;
}
