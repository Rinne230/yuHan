#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define rep(i, j, k) for (int i = (j); i <= (k); i++)
#define per(i, j, k) for (int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 0x7fffffff;
ll dp[101][10001];//dp[j][k]表示在前i个字符里有j个1字符，并且有k个01/10数对的交换次数
ll tmp[101][10001];
void solve()
{
    string s;
    cin >> s;
    int n = (int)s.length();
    s = " " + s;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += (s[i] == '1');
    int com = (n - cnt) * cnt / 2;
    for (int i = 0; i <= cnt; i++)
        for (int j = 0; j <= com; j++)
            dp[i][j] = inf;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= cnt; j++)
            for (int k = 0; k <= com; k++)
                tmp[j][k] = dp[j][k], dp[j][k] = inf;
        for (int j = 0; j <= cnt; j++)
            for (int k = 0; k <= com; k++)
            {
                int st;
                if (s[i] == '0')
                    st = 0;
                else
                    st = 1;
                dp[j][k] = min(dp[j][k], tmp[j][k] + st);
                if (s[i] == '1')
                    st = 0;
                else
                    st = 1;
                dp[j + 1][k + i - 1 - j] = min(dp[j + 1][k + i - 1 - j], tmp[j][k] + st);
            }
    }
    dp[cnt][com] >>= 1;
    cout << dp[cnt][com] << endl;
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