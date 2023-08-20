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
    ll n, k;
    ll ans = 0, id = 0, indx = 0;
    cin >> n >> k;
    vector<pll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].first, a[i].second = i;
    auto b = a;
    sort(a.begin() + 1, a.end());
    for (int i = 2; i <= n; i++)
    {
        ll now = 0;
        for (int j = 0; j < k; j++)
        {
            ll l = (a[i - 1].first) & (1ll << j), r = (a[i].first) & (1ll << j), tmp = 1ll << j;
            if (((l ^ tmp) & (r ^ tmp)) > 0)
                now += tmp;
        }
        if ((((a[i - 1].first) ^ now) & ((a[i].first) ^ now)) >= ans)
        {
            ans = ((a[i - 1].first) ^ now) & ((a[i].first) ^ now);
            id = now;
            indx = i - 1;
        }
    }
    ll l = min(a[indx].second, a[indx + 1].second);
    ll r = max(a[indx].second, a[indx + 1].second);
    cout << l << " " << r << " " << id << "\n";
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