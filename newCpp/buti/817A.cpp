#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e4 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

int pos[205], num[10005];
int dp[10005][10005];

void solve()
{
    int n, m, l;
    cin >> n;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        pos[i] = x;
    }
    cin >> l;
    for (int i = 1; i <= l; i++)
    {
        cin >> num[i];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            int mx = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            if (pos[i] == num[j])
                dp[i][j] = mx + 1;
            else
                dp[i][j] = mx;
        }
    }
    cout << dp[m][l] << endl;
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