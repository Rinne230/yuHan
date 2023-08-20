#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2510;
const ll mod = 10;
const ll inf = 0x3f3f3f3f;
int n, m;
int a[maxn], f[maxn], g[maxn];
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= a[i]; --j)
            f[j] = (f[j] + f[j - a[i]]) % mod;
    g[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (j < a[i])
                g[j] = f[j];
            else
                g[j] = (f[j] - g[j - a[i]]) % mod;
        }
        for (int j = 1; j <= m; j++)
        {
           cout << ((g[j] % mod + mod) % mod);
        }
        cout << endl;
    }
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