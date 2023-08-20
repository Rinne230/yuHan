#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

#define all(x) x.begin(), x.end()
#define endl '\n'

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

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    i64 d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int p, e, k, u;
int a[3], m[] = {23, 28, 33};
void solve()
{
    cin >> p >> e >> k >> u;
    a[0] = p, a[1] = e, a[2] = k;
    int a1 = a[0], m1 = m[0];
    i64 lc;
    for (int i = 1; i <= 2; i++)
    {
        int a2 = a[i], m2 = m[i];
        i64 y1, y2;
        i64 d = exgcd(m1, m2, y1, y2);
        y1 = (i128)y1 * (a2 - a1) / d % (m2 / d);
        lc = (i128)m1 * m2 / d;
        a1 = (((i128)m1 * y1 % lc + a1) % lc + lc) % lc;
        m1 = lc;
    }
    if (a1 <= u) a1 += lc;
    cout << a1 - u << endl;
 }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}