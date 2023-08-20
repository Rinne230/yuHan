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
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

void solve()
{
    ll n, x, y, r;
    cin >> n >> x >> y >> r;
    vector<ll> B(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> B[i];
    sort(B.begin() + 1, B.end());
    ll ans = 0, sum = 0;
    for (ll i = 1; i <= n; ++i)
    {
        if (sum >= r)
        {
            ans += B[i] * B[i];
            continue;
        }
        ll tmp = 0;
        ll cnt1 = B[i] / x;
        ll cnt2 = B[i] / y;
        for (ll k = 0; k <= cnt1; ++k)
            for (ll j = 0; j <= cnt2; ++j)
                if (k * x + j * y > tmp && k * x + j * y <= B[i])
                    tmp = 1ll * k * x + j * y;
        if (tmp + sum >= r)
            for (ll k = 0; k <= cnt1; ++k)
                for (ll j = 0; j <= cnt2; ++j)
                    if (k * x + j * y + sum >= r && k * x + j * y <= B[i])
                        tmp = min(tmp, k * x + j * y);
        
        ans += 1ll * (B[i] - tmp) * (B[i] - tmp);
        sum += 1ll * tmp;
    }
    if (sum >= r)
    {
        cout << ans << endl;
        return;
    }
    cout << -1 << endl;
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