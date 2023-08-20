#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
int a[maxn], b[maxn];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    map<int, int> mp1, mp2;
    for (int i = 1; i <= n; ++i)
    {
        int len = 1;
        while (i + 1 <= n && a[i] == a[i + 1]) len++, i++;
        mp1[a[i]] = max(mp1[a[i]], len);
    }

    for (int i = 1; i <= n; ++i)
    {
        int len = 1;
        while (i + 1 <= n && b[i] == b[i + 1]) len++, i++;
        mp2[b[i]] = max(mp2[b[i]], len);
    }
    int ans = 0;
    for (auto p : mp1)
        ans = max(ans, p.second + mp2[p.first]);
    for (auto p : mp2)
        ans = max(ans, p.second + mp1[p.first]);
    cout << ans << endl;
}

int main()
{
    ios;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
