#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

void solve(){
    int n;
    cin >> n;
    int mn1 = inf, mn2 = inf;
    ll ans = 0;
    for (int i = 1, m; i <= n; ++i){
        cin >> m;
        vector<int> a(m);
        for (int i = 0; i < m; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        ans += a[1];
        mn1 = min(mn1, a[0]);
        mn2 = min(mn2, a[1]);
    }
    ans -= (mn2 - mn1);
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