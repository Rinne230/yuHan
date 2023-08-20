#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 5e5 + 9;
const int mod = 1e9 + 7;
int fpow(int x, int p)
{
    int ans = 1;
    while (p)
    {
        if (p & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return ans;
}
int l[N], r[N], x[N], y[N];
int p[N], q[N], z[N], vis[N];
int c[N], num[N];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i] >> x[i] >> y[i];
        z[l[i]]++, z[x[i]]++;
        p[l[i]]++, p[r[i] + 1]--;
        p[x[i]]++, p[y[i] + 1]--;
        int ll = max(l[i], x[i]), rr = min(y[i], r[i]);
        if (ll <= rr)
        {
            q[ll]++;
            q[rr + 1]--;
            vis[min(l[i], x[i])] = 2;
            if (vis[ll] == 0)
                vis[ll] = 1;//是否是交区间起点
            c[ll]++;//交区间起点数
        }
        else
        {
            vis[l[i]] = 2, vis[x[i]] = 2;
        }
    }
    num[0] = 1;
    for (int i = 1; i <= 500000; i++)
    {
        num[i] = (num[i - 1] + fpow(2, i) % mod) % mod;
        p[i] += p[i - 1];
        q[i] += q[i - 1];
    }
    int ans = 0;
    for (int i = 1; i <= 500000; i++)
    {
        if (p[i] - q[i] == n)
        {
            if (z[i])
            {
                if (vis[i] == 1)//是交区间起点
                {
                    int t;
                    if (q[i] - c[i] - 1 < 0)
                        t = 0;
                    else
                        t = num[q[i] - c[i] - 1];
                    ans = (ans + num[q[i] - 1] - t + mod) % mod;//去掉不不作为交区间起点的方案数
                }
                else
                    ans = (ans + fpow(2, q[i])) % mod;
            }
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios;
    int t = 1;
    while (t--)
    {
        solve();
    }
}
