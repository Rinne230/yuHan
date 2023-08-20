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

void solve()
{
    ll res = 0;
    ll tmp, mx = 9, cnt = 0;
    cin >> tmp;
    while (tmp >= mx)
    {
        cnt++;
        res += (mx - ((mx + 1) / 10 - 1)) * cnt;
        mx = mx * 10 + 9;
    }
    cnt++;
    res += (tmp - ((mx + 1) / 10 - 1)) * cnt;
    cout << res << endl;
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