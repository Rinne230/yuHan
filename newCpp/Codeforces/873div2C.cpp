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
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    ll ans = 1;
    int cnt = 0;
    rep(i, 1, n) ans = (ans * (lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin() - 1 - cnt++)) % mod;
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