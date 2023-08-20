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

ll Sqrt(ll x)
{
    ll k = sqrtl(x);
    while (k * k < x)
        k++;
    while (k * k > x)
        k--;
    return k;
}
void solve()
{
    ll n, a, b, cnt = 0;
    bool ok1 = 1, ok2 = 1;
    cin >> n >> a >> b;
    while (n)
    {
        ll x = n - 1, y = (n + a) >> 1, z = Sqrt(n + b);
        vector<ll> w;
        w.push_back(x);
        if (y >= n)
            ok1 = 0;
        if (z >= n)
            ok2 = 0;
        bool ok3 = 0;
        if (ok1)
            w.push_back(y), ok3 = 1;
        if (ok2)
            w.push_back(z), ok3 = 1;
        n = *min_element(w.begin(), w.end());
        cnt++;
        if (!ok3)
            cnt += n, n = 0;
    }
    cout << cnt << "\n";
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