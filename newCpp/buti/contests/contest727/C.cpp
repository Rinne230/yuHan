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
    int n, now = 0;
    i64 ans = MAXN_64;
    cin >> n;
    vector<int> cnt(n + 1);
    vector<pii> a;
    for (int i = 1; i <= n; i++)
    {
        int x, m;
        cin >> m;
        while (m--)
        {
            cin >> x;
            a.emplace_back(x, i);
        }
    }
    sort(a.begin(), a.end());
    int l = 0, len = a.size();
    for (int r = 0; r < len; r++)
    {
        auto [val, id] = a[r];
        if (!cnt[id])
            now++;
        cnt[id]++;
        if (now < n)
            continue;
        ans = min(ans, val - a[l].first);
        while (now == n && l <= r)
        {
            cnt[a[l].second]--;
            if (!cnt[a[l].second])
            {
                l++, now--;
                break;
            }
            l++;
        }
        l--, cnt[a[l].second]++, now++;
        ans = min(ans, val - a[l].first);
    }
    cout << ans << "\n";
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