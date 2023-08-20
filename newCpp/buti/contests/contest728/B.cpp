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
    i64 n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++)
    {
        auto &[val, id] = a[i];
        cin >> val, id = i;
    }
    sort(a.begin(), a.end());
    int ll = 0, rr = n - 1;
    for (int i = 1; i < n; i++)
    {
        int l = ll, r = rr;
        int now = 0;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            auto &[val, id] = a[mid];
            if (abs(val - a[l].first) <= abs(val - a[r].first))
                now = max(now, mid), l = mid + 1;
            else
                r = mid - 1;
        }
        if (now - ll + 1 >= rr - now)
            rr--;
        else
            ll++;
    }
    cout << a[ll].second + 1 << "\n";
    return 0;
}