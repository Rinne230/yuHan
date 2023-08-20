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

void solve()
{
    i64 p1, r1;
    int n;
    cin >> n;
    cin >> p1 >> r1;
    bool flag = false;
    for (int i = 0; i < n - 1; i++)
    {
        i64 p2, r2;
        cin >> p2 >> r2;
        if (flag == true)
            continue;
        i64 y1, y2;
        i64 d = exgcd(p1, p2, y1, y2);
        if ((r2 - r1) % d != 0)
            flag = true;
        y1 = (i128)y1 * (r2 - r1) / d % (p2 / d);
        i64 lc = (i128)p1 * p2 / d;
        r1 = (((i128)p1 * y1 % lc + r1) % lc + lc) % lc;
        p1 = lc;
    }
    if (flag)
        cout << -1 << endl;
    else
        cout << r1 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}