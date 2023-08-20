#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
map<ll, ll> m, vis;

void solve()
{
    ll n, ans = 0;
    cin >> n;
    m.clear();
    vis.clear();
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x <= n)
        {
            m[x]++;
        }
    }
    for (auto x : m)
    {
        int tmp = x.first;
        int num = x.second;
        for (int i = tmp; i <= n; i += tmp)
        {
            vis[i] += num;
        }
    }
    for (auto x : vis)
        ans = max(ans, x.second);
    cout << ans << endl;
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