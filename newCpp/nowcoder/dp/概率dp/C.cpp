#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;

template <typename Tp>
inline void read(Tp &x)
{
    x = 0;
    int f = 0;
    char ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9'))
        ch = getchar();
    if (ch == '-')
        f = 1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    if (f)
        x = -x;
}

int n;
double a[1010];
double dp[1010];

void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lf", &a[i]);

    dp[n] = a[n];
    for (int i = n - 1; i >= 1; i--)
    {
        int num = min(6, n - i);
        dp[i] = a[i];
        for (int j = i + 1; j <= i + 6; j++)
        {
            dp[i] += dp[j] / num;
        }
    }
    printf("%.10lf",dp[1]);
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