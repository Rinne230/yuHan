#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

ll a[maxn];
pll x[maxn];

void solve()
{
    int n;
    cin >> n;
    long long s1 = 0, s2 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i].first;
        x[i].second = i;
        s2 += x[i].first;
    }
    sort(x + 1, x + n + 1);
    for (int i = 1; i <= n; i++)
    {
        s2 -= x[i].first;
        s1 += x[i].first;
        a[x[i].second] = n + 1ll * x[i].first * (2 * i - n) - s1 + s2;
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " \n"[i == n];
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