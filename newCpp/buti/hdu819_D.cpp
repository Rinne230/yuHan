#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define rep(i, j, k) for (int i = (j); i <= (k); i++)
#define per(i, j, k) for (int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
typedef __int128 i128;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;
i128 inv[maxn];

i128 qmi(i128 a, i128 b)
{
    i128 res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res;
}

i128 read()
{
    i128 x = 0;
    bool f = 0;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = 1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return f ? -x : x;
}

inline void write(i128 x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
void solve()
{
    i128 n, m, k;
    n = read(), m = read(), k = read();
    if (n == k)
    {
        write(n);
        putchar('\n');
        return;
    }

    i128 tmp = m * (n - k) * k * inv[n] % mod;
    i128 ans = tmp;
    for (int i = 1; i < k; ++i)
    {
        tmp = (tmp * (k - i) % mod) * inv[n - i] % mod;
        ans = (tmp + ans) % mod;
    }
    i128 res = (n + ans) % mod;
    write(res);
    putchar('\n');
}

int main()
{
    ios;
    i128 t = 1;
    inv[1] = 1;
    for (int i = 2; i < maxn - 5; i++)
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    t = read();
    while (t--)
    {
        solve();
    }
    return 0;
}