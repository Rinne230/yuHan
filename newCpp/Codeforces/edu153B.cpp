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
const ll inf = 0x3f3f3f3f;

void solve(){
    ll m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;
    ll tmp1 = max(0ll, m / k - ak);
    ll tmp2 = max(0ll, m % k - a1);
    a1 = a1 - (m % k - tmp2);
    tmp1 = max(0ll, tmp1 - a1 / k);
    cout << tmp1 + tmp2 << endl;
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