#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 50;
const ll mod = 998244353;
ll a[maxn];
ll f[maxn][3];

void solve()
{
    //flag表示是否能直接返回值，也就是说前pos-1位与原数是否不同
    //相同则这一位收到限制需要继续递归求解
    //不同则不受限制，如果之前算过了可以直接返回
    function<ll(ll, ll, bool)> dp = [&](ll pos, ll st, bool flag){//st:0无38无4;1为3;2非法
        if (pos == 0) return ll(st == 2);
        if (flag && f[pos][st] != -1) return f[pos][st];
        int x = flag ? 9 : a[pos];
        ll ans = 0;
        for (int i = 0; i <= x; ++i){
            if (i == 4 || st == 2 || (st == 1 && i == 8)) ans += dp(pos - 1, 2, flag || i < x);
            else if (i == 3) ans += dp(pos - 1, 1, flag || i < x);
            else ans += dp(pos - 1, 0, flag || i < x);
        }
        if (flag) f[pos][st] = ans;
        return ans;
    };
    function<ll(ll)> clac = [&](ll x)
    {
        memset(a, 0, sizeof a);
        memset(f, -1, sizeof f);
        int pos = 0;
        while (x)
        {
            x /= 10;
        }
        return dp(pos, 0, 0);
    };
    int n, m;
    while (cin >> n >> m)
    {
        if (!n && !m)
            break;
        cout << clac(m) - clac(n - 1) << '\n';
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