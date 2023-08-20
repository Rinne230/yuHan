#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef __int128_t ll;
const long long maxn = 2e5 + 10;
ll fpow(ll x, ll t)
{
    ll res = 1;
    for (; t; t >>= 1, x = 1ll * x * x)
        if (t & 1)
            res = 1ll * res * x;
    return res;
}
void put(ll k)
{
    stack<char> s;
    do
    {
        s.push((k % 10) + '0');
        k /= 10;
    } while (k);
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}
int main()
{
    ios;
    long long nn;
    ll n, odnum, evnum, res = 0;
    cin >> nn, n = nn;
    if (n & 1)
        evnum = (n >> 1), odnum = (n >> 1) + 1;
    else
        evnum = odnum = (n >> 1);
    for (ll i = 1, nd, md; fpow(5, i) <= n; ++i)
    {
        ll tmpo = fpow(5, i), tmpe = tmpo * 2;
        ll tmpodnum, tmpevnum;
        tmpodnum = odnum - (tmpo / 2);
        tmpevnum = evnum - (tmpe / 2 - 1);
        // 处理奇数部分
        if (tmpodnum > 0)
        {
            nd = tmpodnum / tmpo;
            md = tmpodnum % tmpo;
            res += (nd + 1) * (nd) / 2 * tmpo;
            res += md * (nd + 1);
        }
        // 处理偶数部分
        if (tmpevnum > 0)
        {
            nd = tmpevnum / tmpo;
            md = tmpevnum % tmpo;
            res += (nd + 1) * (nd) / 2 * tmpo;
            res += md * (nd + 1);
        }
    }
    put(res);
    return 0;
}