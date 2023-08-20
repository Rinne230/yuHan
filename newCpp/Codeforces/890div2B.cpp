#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (n == 1){
        cout << "NO" << endl;
        return;
    }
    ll les = 0, mor = 0;
    for (int i = 1; i <= n; ++i){
        if (a[i] > 1) {
            les += a[i] - 1;
        }else{
            mor++;
        }
    }
    if (mor > les) cout << "NO" << endl;
    else cout << "YES" << endl;
  
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