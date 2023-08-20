/***
 * 	Cheeeeen the Cute Cat
 */
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
    bool flag = 1;
    int n;
    cin >> n;
    vector<vector<int>> G(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> G[i][j];
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
            if (G[j][i] == 1)
                cnt = 1;
        if (!cnt)
            flag = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
            if (G[i][j] == 1)
                cnt = 1;
        if (!cnt)
            flag = 0;
    }
    if (flag)
        cout << n << endl;
    else
        cout << n - 1 << endl;
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