#include <bits/stdc++.h>
#define lowbit(x) x & (-x)
using namespace std;
using i64 = long long;
using i128 = __int128_t;
using pid = pair<int, double>;
using pii = pair<i64, i64>;
constexpr int mod = 998244353;
constexpr int MAXN_32 = 2e9;
constexpr i64 MAXN_64 = 1e18;

void put(i128 k)
{
    stack<int> s;
    do
    {
        s.push(k % 10);
        k /= 10;
    } while (k);

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << "\n";
}

void solve()
{
    i64 n;
    i128 ans = 0, sum = 0;
    cin >> n;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum += a[i];
    for (int i = 1; i <= n; i++)
        ans += (i128)a[i] * (sum - a[i]);
    put(ans / 2);
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