#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 20;
const ll mod = 20020219;
ll len[maxn];
ll a[maxn];
ll f[maxn][maxn][maxn];
ll l, r, n;

void solve()
{
    // flag表示是否能直接返回值，也就是说前pos-1位与原数是否不同
    // 相同则这一位收到限制需要继续递归求解
    // 不同则不受限制，如果之前算过了可以直接返回
    function<ll(ll, ll, ll, bool)> dp = [&](ll pos, ll pre, ll sum, bool flag)
    {
        if (pos == 0)
            return ll(!pre && !sum);
        if (flag && f[pos][pre][sum])
            return f[pos][pre][sum];
        int up = flag ? 9 : a[pos];
        ll ans = 0;
        for (int i = 0; i <= up; i++)
        {
            ans += dp(pos - 1, (pre * 10 + i) % 7, (sum + i) % 7, flag | (i < up));
        }
        if (flag)
            f[pos][pre][sum] = ans;
        return ans;
    };
    function<ll(ll)> clac = [&](ll x)
    {
        int id = 0;
        while (x)
        {
            a[++id] = x % 10;
            x /= 10;
        }
        return dp(id, 0, 0, 0);
    };

    ll l, r;
    while (cin >> l >> r)
    {
        if (l == 0 && r == 0)
            return;
        cout << clac(r) - clac(l - 1) << "\n";
    }
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