#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 1024523;
const ll inf = 0x3f3f3f3f;
int n, m, dp[502][502][502];
string a, b;
void solve()
{
    cin >> n >> m;
    cin >> a >> b;
    dp[0][0][0] = 1;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            for (int k = 0; k <= n; ++k){
                int l = i + j - k;
                if (l < 0 || l > m) continue;
                if (a[i] == a[k])
                    dp[i + 1][j][k + 1] = (dp[i + 1][j][k + 1] + dp[i][j][k]) % mod;
                if (a[i] == b[l])
                    dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j][k]) % mod;
                if (b[j] == a[k])
                    dp[i][j + 1][k + 1] = (dp[i][j + 1][k + 1] + dp[i][j][k]) % mod;
                if (b[j] == b[l])
                    dp[i][j + 1][k] = (dp[i][j + 1][k] + dp[i][j][k]) % mod;
            }
    cout << dp[n][m][n];
}

int main()
{
    ios;
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}