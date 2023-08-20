#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define rep(i, j, k) for(int i = (j); i <= (k); i++)
#define per(i, j ,k) for(int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 1e18;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n * m + 1);
    for (int i = 1; i <= n * m; ++i) cin >> a[i];
    sort(a.begin() + 1, a.end());
    ll ans = 0;
    ans = max(ans, 1ll * (a[n * m] - a[1]) * (max(n, m) - 1) + (a[n * m] - a[2]) * (min(n, m) - 1) + (a[n * m] - a[1]) * ((n - 1) * (m - 1)));
    ans = max(ans, 1ll * (a[n * m] - a[1]) * (max(n, m) - 1) + (a[n * m - 1] - a[1]) * (min(n, m) - 1) + (a[n * m] - a[1]) * ((n - 1) * (m - 1)));
    cout << ans << endl;
}

int main(){
    ios;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}