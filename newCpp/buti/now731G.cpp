/***
 * Go to Play Maimai DX
 */
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
    ll n, k;
    cin >> n >> k;
    map<ll, ll> cnt;
    vector<ll> a(n + 1);
    int l = 1, r = 1, num = 0, ans = maxn;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    while (l <= r && r <= n + 1)
    {
        if (num < 4)
        {
            r++;
            cnt[a[r - 1]]++;
            if (a[r - 1] == 4 && cnt[a[r - 1]] == k)
                num++;
            else if (a[r - 1] != 4 && cnt[a[r - 1]] == 1)
                num++;
        }
        else
        {
            if (ans > r - l)
                ans = r - l;
            cnt[a[l]]--;
            if (a[l] == 4 && cnt[a[l]] < k)
                num--;
            else if (a[l] != 4 && cnt[a[l]] == 0)
                num--;
            l++;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}