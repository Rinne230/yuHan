#include <bits/stdc++.h>
#define fup(i, s, n) for (int i = s; i <= n; i++)
#define fdn(i, n, s) for (int i = n; i >= s; i--)
using namespace std;
using i64 = long long;
using pid = pair<int, double>;
using pii = pair<int, int>;
constexpr int mod = 998244353;
constexpr int MAXN_32 = 2e9;
constexpr i64 MAXN_64 = 1e18;
i64 f[5010][10010]{};
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    i64 n, m, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m + m; j++)
        {
            if (i == 1)
            {
                f[i][j] = 1;
                continue;
            }
            for (int k = 0; k <= m + m; k++)
            {
                if (j + k < m + m)
                    continue;
                f[i][min({0ll + k, k + j - m, m + m})] += f[i - 1][j];  
            }
        }
    }
    for (int i = 0; i <= m + m; i++)
        ans += f[n][i];
    cout << ans << "\n";
    return 0;
}