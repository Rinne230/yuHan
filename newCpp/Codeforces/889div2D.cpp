#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
ll a[maxn], s[maxn], ans, n;
bitset<maxn> f; // f[i][j]: 操作到i,已经解锁了后面j张牌的状态是否存在,滚掉第一维

int main()
{
    ios;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], s[i] = s[i - 1] + a[i];

    f[a[1]] = 1, f[0] = 0, ans = a[1]; // 至少拥有第一张牌  
    for (int i = 2; i <= n; i++)
    {
        if (f[i - 1])
            ans = max(ans, s[i] - (i - 1)); // 把值为i-1的那张用来unlock的牌拿走了
        f |= f << a[i];
        f[i - 1] = 0; // 操作之后把上一张牌拿走了
    }
    for (int i = n; i < n * 2; i++)
    {
        if (f[i])
            ans = max(ans, s[n] - i);
    }
    cout << ans;
}
