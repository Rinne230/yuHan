#include <bits/stdc++.h>
#define fup(i, s, n) for (int i = s; i <= n; i++)
#define fdn(i, n, s) for (int i = n; i >= s; i--)
using namespace std;
using i64 = long long;
using ui64 = unsigned long long;
using pid = pair<int, double>;
using pii = pair<i64, i64>;
constexpr ui64 mod = 1e9 + 7;
constexpr int MAXN_32 = 2e9;
constexpr i64 MAXN_64 = 1e18;
void solve()
{
    int n;
    i64 sum1 = 0, sum2 = 0;
    cin >> n;
    vector<pii> a(n);
    for (auto &[i, j] : a)
        cin >> i >> j;
    sort(a.begin(), a.end(), [&](pii &x, pii &y)
         { return (x.first + x.second) > (y.first + y.second); });
    for (int i = 0; i < n; i++)
    {
        auto [x, y] = a[i];
        if (i & 1)
            sum2 += y;
        else
            sum1 += x;
    }
    cout << sum1 - sum2 << "\n";
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}