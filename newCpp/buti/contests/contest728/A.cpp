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
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    i64 n, m, q, rsuml, rsumr, csuml, csumr, ans = 0;
    cin >> n >> m >> q;
    rsuml = rsumr = csuml = csumr = 0;
    vector<int> r(n + 1), c(m + 1), rr(n + 1), cc(m + 1);
    vector<tuple<int, int, int>> query;
    while (q--)
    {
        string a, b;
        int x;
        cin >> a >> x >> b;
        if (a == "row")
        {
            if (b == "on")
            {
                query.emplace_back(0, 1, x);
            }
            else
            {
                query.emplace_back(0, 0, x);
            }
        }
        else
        {
            if (b == "on")
            {
                query.emplace_back(1, 1, x);
            }
            else
            {
                query.emplace_back(1, 0, x);
            }
        }
    }
    for (auto it = query.rbegin(); it != query.rend(); it++)
    {
        auto [p, cur, x] = *it;
        if (p == 0 && r[x])
            continue;
        if (p == 1 && c[x])
            continue;
        if (p == 0)
        {
            r[x] = 1;
            if (cur)
                ans += m - csuml - csumr, rsuml++;
            else
                rsumr++;
        }
        else
        {
            c[x] = 1;
            if (cur)
                ans += n - rsuml - rsumr, csuml++;
            else
                csumr++;
        }
    }
    cout << ans << "\n";
    return 0;
}