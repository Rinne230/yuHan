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
    function<ll(ll, ll, ll)> quickPow = [&](ll a, ll b, ll c)
    {
        a %= c;
        ll res = 1;
        while (b > 0)
        {
            if ((b & 1) == 1)
            {
                res = (res * a) % c;
            }
            a = (a * a) % c;
            b >>= 1;
        }
        return res;
    };
    ll n, m, k;
    cin >> n >> m >> k;
    if (m == 1) {
        cout << 1 << endl;
        return;
    }
    cout << (quickPow(m, n - k, mod) + mod) % mod << endl;
}

int main()
{
    ios;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}