#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ID(a, b) (((a) << 2) | (b))
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 10;
const ll mod = 998244353;

int n;
char s[maxn + 5];
int f[maxn + 5][20];

void solve()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
    {
        int c = (s[i] == 'R' ? 1 : (s[i] == 'G' ? 2 : 3));
        for (int a = 0; a <= 3; a++)
            for (int b = 0; b <= 3; b++)
                f[i][ID(a, b)] = f[i - 1][ID(a, b)];
        for (int a = 0; a <= 3; a++)
            for (int b = 0; b <= 3; b++)
                if (a == b && b == c)
                {
                    int F = f[i - 1][ID(a, b)] + 1;
                    for (int d = 1; d <= 3; d++)
                        f[i][d] = max(f[i][d], F);
                }
                else if (a && b && c && a != b && a != c && b != c)
                {
                    int F = f[i - 1][ID(a, b)];
                    for (int d = 1; d <= 3; d++)
                        for (int e = 1; e <= 3; e++)
                            f[i][ID(d, e)] = max(f[i][ID(d, e)], F);
                }
                else
                    f[i][ID(b, c)] = max(f[i][ID(b, c)], f[i - 1][ID(a, b)]);
    }
    int ans = 0;
    for (int a = 0; a <= 3; a++)
        for (int b = 0; b <= 3; b++)
            ans = max(ans, f[n][ID(a, b)]);
    printf("%d\n", ans);
}
int main()
{
    // freopen("1006.in", "r", stdin);
    // freopen("1006.out", "w", stdout);
    ios;
    memset(f[0], 192, sizeof(f[0]));
    f[0][0] = 0;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}