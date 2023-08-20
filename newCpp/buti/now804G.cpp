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
void solve()
{
    i64 a, b, c;
    cin >> a >> b >> c;
    if (c == 0 && a != 0 && b != 0)
        cout << "NO\n";
    else if (c % gcd(a, b) == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
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