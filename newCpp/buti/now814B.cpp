#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e8;
int phi(int x)
{
    int res = x;
    for (int i = 2; i <= x / i; i++)
    {
        if (x % i == 0)
            res = res / i * (i - 1);
        while (x % i == 0)
            x /= i;
    }
    if (x != 1)
        res = res / x * (x - 1);
    return res;
}
int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int qmi(int a, int b, int p)
{
    int res = 1;
    a %= p;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
int solve(int a, int p)
{
    if (p == 1)
        return 0;
    int m = phi(p);
    int j = solve(a % gcd(m, p), gcd(m, p));
    j += m;
    int x, y;
    int d = exgcd(m, p, x, y);
    int mod = p / d;
    int ans = 0;
    ans = (((x * (qmi(a, j, mod * d) - j + mod * d)) % (mod * d) + (mod * d)) % (mod * d) / d);
    return ans * m + j;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, m;
        cin >> a >> m;
        int ans = solve(a, m);
        cout << ans << endl;
    }
}