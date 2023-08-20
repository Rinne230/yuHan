#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 10;
const ll mod = 998244353;

void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> pre(n + 1), pree(n + 1), preo(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        pre[i] = pre[i - 1] + x;
        pree[i] = pree[i - 1] + !(pre[i] & 1);
        preo[i] = preo[i - 1] + (pre[i] & 1);
    }
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        if (((pre[r] - pre[l - 1]) & 1))
        {
            cout << "NO\n";
            continue;
        }
        if (pre[l - 1] & 1)
        {
            int num = preo[r] - preo[l - 1];
            if (k <= num)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
        {
            int num = pree[r] - pree[l - 1];
            if (k <= num)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
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