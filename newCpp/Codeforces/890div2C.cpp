#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    auto check = [&](int mid)
    {
        for (int i = 0; i < n; i++)
        {
            int remain = k;
            for (int j = i, v = mid; j < n; j++, v--)
            {
                if (a[j] >= v)
                {
                    return true;
                }
                if (remain < v - a[j])
                    break;
                remain -= v - a[j];
            }
        }
        return false;
    };

    int  l = *max_element(a.begin(), a.end());
    int r = 1e9;
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << r << '\n';
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