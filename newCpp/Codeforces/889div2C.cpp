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
    int n, maxn = -30, minn = 30, low = 0, up = 0, id1 = 0, id2 = 0;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > 0)
            up++;
        else if (a[i] < 0)
            low++;
        if (a[i] > maxn)
            maxn = a[i], id1 = i;
        if (a[i] < minn)
            minn = a[i], id2 = i;
    }
    if (is_sorted(a.begin() + 1, a.end()))
    {
        cout << "0\n";
        return;
    }
    if (minn >= 0)
    {
        cout << n - 1 << "\n";
        for (int i = 2; i <= n; i++)
            cout << i << " " << i - 1 << "\n";
        return;
    }
    if (maxn <= 0)
    {
        cout << n - 1 << "\n";
        for (int i = n - 1; i; i--)
            cout << i << " " << i + 1 << "\n";
        return;
    }
    int cnt = 0, t = maxn;
    while (abs(t) < abs(minn))
        t *= 2, cnt++;
    if (cnt + low + n - 1 <= 31)
    {
        cout << cnt + low + n - 1 << "\n";
        while (cnt--)
            cout << id1 << " " << id1 << "\n";
        for (int i = 1; i <= n; i++)
            if (a[i] < 0)
                cout << i << " " << id1 << "\n";
        for (int i = 2; i <= n; i++)
            cout << i << " " << i - 1 << "\n";
        return;
    }
    cnt = 0, t = minn;
    while (abs(t) < abs(maxn))
        t *= 2, cnt++;
    if (cnt + up + n - 1 <= 31)
    {
        cout << cnt + up + n - 1 << "\n";
        while (cnt--)
            cout << id2 << " " << id2 << "\n";
        for (int i = 1; i <= n; i++)
            if (a[i] > 0)
                cout << i << " " << id2 << "\n";
        for (int i = n - 1; i; i--)
            cout << i << " " << i + 1 << "\n";
        return;
    }
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