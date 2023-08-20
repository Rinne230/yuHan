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
    int n, m;
    cin >> n >> m;
    double pos = 1.0 / n * 2.0;
    double res = 1.0;
    if (n <= 2)
    {
        cout << fixed << setprecision(11) << res << endl;
        return;
    }

    for (int i = 1; i <= m; ++i)
    {
        res *= pos;
    }
    cout << fixed << setprecision(11) << res << endl;
}

int main()
{
    ios;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}