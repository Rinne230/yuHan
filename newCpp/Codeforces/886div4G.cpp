#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
map<pair<int, int>, int> adis, bdis, cdis, ddis;

void init()
{
    adis.clear();
    bdis.clear();
    cdis.clear();
    ddis.clear();
}

void solve()
{
    init();
    ll ans = 0, n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        ans += adis[{0, y}]++;
        ans += bdis[{x, 0}]++;
        ans += cdis[{0, y - x}]++;
        ans += ddis[{0, x + y}]++;
    }
    cout << ans * 2 << endl;
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