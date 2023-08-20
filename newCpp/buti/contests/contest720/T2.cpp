#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
ll power(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = (power(2, n - 1) - 1 + mod) % mod;
        cout << ans << endl;
    }
    return 0;
}
