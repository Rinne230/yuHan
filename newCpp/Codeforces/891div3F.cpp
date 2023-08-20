#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define int ll
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0, x; i < n; ++i)
    {
        cin >> x;
        mp[x]++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int d = x * x - 4 * y;
        if (d < 0)
            cout << 0 << ' ';
        else
        {
            int dd = ::sqrt(d);
            if (dd * dd != d)
            {
                cout << 0 << ' ';
                continue;
            }
            int b1 = (x - dd) / 2, b2 = (x + dd) / 2;
            if (b1 != b2)
                cout << mp[b1] * mp[b2] << ' ';
            else
                cout << mp[b1] * (mp[b2] - 1) / 2 << ' ';
        }
    }
    cout << '\n';
    return;
}

signed main()
{
    ios;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}