/**
 * @file 青蛙的约会
 * @author atri
 * @brief 
 * @version 0.1
 * @date 2023-08-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
        return x = 1, y = 0, a;
    int r = exgcd(b, a % b, x, y);
    tie(x, y) = make_tuple(y, x - (a / b) * y);
    return r;
}

void solve()
{
    ll x, y, n, m, l, u, v, d, c;
    cin >> x >> y >> n >> m >> l;
    if (n > m)
    {
        d = exgcd(n - m, l, u, v);
        c = y - x;
    }
    else
    {
        d = exgcd(m - n, l, u, v);
        c = x - y;
    }
    if ((x - y) % d)
    {
        cout << "Impossible" << endl;
        return;
    }
    u *= c / d;
    l = abs(l / d);
    cout << (u % l + l) % l << endl;
}

int main()
{
    ios;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}