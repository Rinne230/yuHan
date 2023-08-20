#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
ll a[maxn];
ll dp[maxn][2];

void solve()
{
    memset(dp, 0, sizeof dp);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    dp[1][0] = a[1];
    dp[1][1] = -a[1];
    dp[2][0] = a[1] + a[2];
    dp[2][1] = -a[1] - a[2];
    for (int i = 3; i <= n; ++i)
    {
        dp[i][0] = a[i] + max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = -1ll * a[i] + max(dp[i - 1][0] - a[i - 1] - a[i - 1], dp[i - 1][1] + a[i - 1] + a[i - 1]);
    }
    cout << max(dp[n][1], dp[n][0]) << endl;
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