#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef long long LL;
const int mod = 998244353;
LL res = 1;

LL powx(LL a, LL b)
{
    LL res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a;
        a = a * a, b >>= 1;
    }
    return res;
}

LL qmi(LL a, LL b, LL p)
{
    LL res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        a = a * (LL)a % p;
        b >>= 1;
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    LL n, m;
    cin >> n >> m;
    m = m + n;

    int t = 0;
    while (n >= powx(2, t + 2) - 1)
        t++;

    LL mul = 1;
    LL a = qmi(2, mod - 2, mod);
    LL b = powx(2, t + 1);
    LL c = 1;

    for (int i = 0; i <= t; i++)
        c = c * a % mod;

    mul = (c * (b - 1) % mod) % mod;

    while (b * 2 - 1 < m){
        int x = b * 2 - 1 - n;
        n = b * 2 - 1;
        LL d = qmi(mul, x, mod);
        res = res * d % mod;
        b = b * 2;
        c = c * a % mod;
        mul = (c * (b - 1) % mod) % mod;
    }

    int x = m - n;
    LL d = qmi(mul, x, mod);
    res = res * d % mod;
    cout << res << endl;
    return 0;
}