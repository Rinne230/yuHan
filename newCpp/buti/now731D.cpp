/***
 * Cirno's Perfect Equation Class
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

void solve()
{
    ll k, c, n, ans = 0;
    function<ll(ll, ll)> gcd = [&](ll a, ll b)
    {
        return b > 0 ? gcd(b, a % b) : a;
    };
    function<bool(ll)> check = [&](ll x)
    {
        if (!(c - x))
            return false;
        if ((c - x) % k == 0 && gcd(x, (c - x) / k) >= n)
            return true;
        return false;
    };
    cin >> k >> c >> n;
    for (int i = 1; i * i <= c; ++i)
    {
        if (c % i == 0)
        {
            if (check(i))
                ans++;
            if (i * i != c && check(c / i))
                ans++;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}