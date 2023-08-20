#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 1e6 + 10;
typedef long long ll;
ll soc[maxn];

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<int, int>> node;
    for (ll i = 1, u, v; i <= m; ++i)
    {
        cin >> u >> v;
        soc[u]++;
        if (soc[v])
        soc[v]--;

    }
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