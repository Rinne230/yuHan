#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
ll a[maxn];

void solve()
{
    int n;
    long long c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    long long l = 0, r = 1e9;
    while (l < r)
    {
        long long m = (l + r) >> 1;
        __int128 tot = 0;
        for (int i = 1; i <= n; i++){
            tot = tot + (a[i] + 2 * m) * (a[i] + 2 * m);
        }
        if (tot > c)
        {
            r = m;
        }
        else if (tot < c)
        {
            l = m + 1;
        }
        else
            break;
    }
    cout << (l + r) / 2 << endl;
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
