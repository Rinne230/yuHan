#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 1e13;

void solve()
{
    ll n, m, d, c = 1, mn = inf, cnt = 0;
    cin >> n >> m >> d;
    vector<ll> dis(m + 2), tim(m + 2);
    dis[0] = 1, dis[m + 1] = n;
    for (int i = 1; i <= m; ++i)
    {
        cin >> dis[i];
        tim[i] = (dis[i] - dis[i - 1]) / d;
        if ((dis[i] - dis[i - 1]) % d)
            tim[i]++;
        c += tim[i];
    }
    c += (n - dis[m]) / d;
    tim[m + 1] = (n - dis[m]) / d;
    for (int i = 1; i <= m; ++i)
    {
        ll tmp = c - (tim[i] + tim[i + 1]);
        tmp += (dis[i + 1] - dis[i - 1]) / d;
        if ((dis[i + 1] - dis[i - 1]) % d && i < m)
            tmp++;
        if (tmp > mn)
            continue;
        else if (tmp < mn)
        {
            mn = tmp;
            cnt = 1;
        }
        else if (tmp == mn)
            cnt++;
    }
    cout << mn << " " << cnt << endl;
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