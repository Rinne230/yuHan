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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> left0(n);
    vector<int> right1(n);
    left0[0] = -1;
    right1[n - 1] = -1;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            left0[i] = left0[i - 1];
        if (s[i] == '0')
            left0[i] = i;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (i != n - 1)
            right1[i] = right1[i + 1];
        if (s[i] == '1')
            right1[i] = i;
    }
    set<pll> res;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        if (l == r)
            l = r = -1;
        else
        {
            l = right1[l - 1];
            r = left0[r - 1];
            if (l >= r || l == -1 || r == -1)
                l = r = -1;
        }

        pll t = {l, r};
        res.insert(t);
    }

    cout << res.size() << endl;

    return;
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