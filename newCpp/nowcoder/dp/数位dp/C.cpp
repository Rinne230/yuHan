/**
 * @file 数位dp模板
 * @author atrilactose
 * @version 0.1
 * @date 2023-08-02
 *
 * @copyright Copyright (c) 2023
 *
 *
 * 第一行,一个整数T,代表数据组数对于每组数据,
 * 有三个数字 l,r,n
 * 接下来n行，每行一个数字x，接下来一个数len表示数字x在数字串中连续出现的次数不能大于len
 * 对于每组数据
 * 输出一个整数,表示l,r中满足约束的数字个数。(对20020219取模)
 */
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
    function<ll(ll, ll, ll, bool)> dp = [&](ll pos, ll x, ll cnt, bool flag)
    {
        if (pos == 0)
            return 1ll;
        if (flag && f[pos][x][cnt])
            return f[pos][x][cnt];
        int up = flag ? 9 : a[pos];
        ll ans = 0;
        for (int i = 0; i <= up; ++i)
        {
            if (i == x)
            {
                if (cnt + 1 > len[i])
                    continue;
                ans = (ans + dp(pos - 1, i, cnt + 1, flag || (i < up))) % mod;
            }
            else
            {
                ans = (ans + dp(pos - 1, i, 1, flag || (i < up))) % mod;
            }
        }
        if (flag)
            f[pos][x][cnt] = ans % mod;
        return ans % mod;
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

    cin >> l >> r >> n;
    memset(len, 0x3f, sizeof(len));
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        ll x, cnt;
        cin >> x >> cnt;
        len[x] = min(len[x], cnt);
    }
    cout << (clac(r) - clac(l - 1) + mod) % mod << "\n";
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