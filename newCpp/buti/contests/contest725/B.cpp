#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 3010;
const int mod = 1e9 + 7;
typedef long long ll;
ll a[maxn], c[maxn];
ll dp[maxn][maxn];
ll C[maxn][maxn];

void init()
{
    for (int i = 0; i < maxn; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (!j)
            {
                C[i][j] = 1;
            }
            else
            {
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    map<ll, ll> les;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    memcpy(c, a, sizeof(a));
    int len = unique(c, c + n) - c;
    // cout << len << endl;
    for (int i = 0; i < n; ++i)
    {
        a[i] = lower_bound(c, c + len, a[i]) - c + 1;
    }
    // for (int i = 0; i < n; ++i)
    // {
    //     les[a[i]] = (upper_bound(a, a + n, a[i]) - a) - 1;
    // }
    // for (int i = 0; i < n; ++i){
    //     cout << a[i] << ':' << les[a[i]] << endl;
    // }
    int nn = unique(a, a + n) - a;
    for (int i = 0; i < nn; ++i)
    {
        // cout << a[i] << endl;
        dp[a[i]][1] = 1;
    }
    for (int i = 0; i < nn; ++i)
    {
        les[a[i]] = (upper_bound(a, a + nn, a[i]) - a) - 1;
    }
    for (int i = 0; i < nn; ++i)
    {
        for (int l = 2; l <= n; ++l)
        {
            if (les[a[i]] >= l - 1)
            {
                dp[a[i]][l] = C[les[a[i]]][l - 1];
                for (int k = 1; k <= l - 1; ++k)
                {
                    dp[a[i]][l] += dp[a[i]][k];
                }
            }
        }
    }
    ll lst = 0;
    for (int i = 1; i <= nn; ++i)
    {
        ll ans = 0;
        for (int j = 0; j < nn; ++j)
        {
            //cout << j << "-" << i << ":" << dp[a[j]][i] << endl;
            ans = (ans + dp[a[j]][i]) % mod;
        }
        cout << ans << endl;
        lst = ans;
    }
    for (int i = nn + 1; i <= n; ++i)
    {
        cout << lst << endl;
    }
}

int main()
{
    ios;
    init();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
2
3
1 2 3
3
2 3 3
*/