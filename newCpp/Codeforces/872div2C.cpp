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
    int lf = 0, ri = 0;
    vector<int> v(m + 2, 0);
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp == -1)
        {
            lf++;
        }
        else if (tmp == -2)
        {
            ri++;
        }
        else
        {
            if (!v[tmp])
                cnt++;
            v[tmp] = 1;
        }
    }
    for (int i = 1; i <= m + 1; i++)
        v[i] += v[i - 1];
    for (int i = 1; i <= m; i++)
    {
        if (v[i] - v[i - 1])
        {
            ans = max(ans, min(i - v[i], lf) + min(m - (v[m] - v[i]) - i, ri));
        }
    }
    ans = max(ans, min(m - (v[m] - v[0]), ri));
    ans = max(ans, min(m - v[m], lf));
    cout << ans + cnt << endl;
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