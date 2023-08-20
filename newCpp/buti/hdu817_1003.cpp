#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define rep(i, j, k) for (int i = (j); i <= (k); i++)
#define per(i, j, k) for (int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;

int t, n, k;

ll power(ll p, int k = mod - 2)
{
    ll ans = 1;
    while (k)
    {
        if (k % 2 == 1)
            ans = ans * p % mod;
        p = p * p % mod;
        k /= 2;
    }
    return ans;
}
ll fact[1000005];
void init(int L)
{
    fact[0] = 1;
    rep(i, 1, L) fact[i] = fact[i - 1] * i % mod;
}

void solve()
{
    cin >> n >> k;
    ll ans;
    if (n == k)
        ans = fact[n] * fact[n - 1] % mod;
    else
        ans = fact[n] * fact[k] % mod * power(k, n - k - 1) % mod;
    printf("%lld\n", ans);
}

int main()
{
    ios;
    init(1000000);
    cin >> t;
    while (t--)
        solve();
    return 0;
}