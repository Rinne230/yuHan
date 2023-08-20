#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define rep(i, j, k) for (int i = (j); i <= (k); i++)
#define per(i, j, k) for (int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    string s1;
    string s2;
    cin >> s1 >> s2;
    int cnt1 = 0, cnt2 = 0, cnt;
    for (int i = 0; i < n; ++i){
        if (s1[i] == '1') cnt1++;
    }
    for (int i = 0; i < n; ++i){
        if (s2[i] == '1') cnt2++;
    }
    cnt = cnt1 + cnt2;
    if (cnt > n) cnt = n - (cnt - n);
    for (int i = 1; i <= cnt; ++i) cout << 1;
    for (int i = cnt + 1; i <= n; ++i) cout << 0;
    cout << endl;
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