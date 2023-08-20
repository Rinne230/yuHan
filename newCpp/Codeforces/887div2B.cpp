#include<bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;

ll dep(ll a, ll b, ll deep){
    if (a - b > b) return deep;
    return dep(b, a - b, deep + 1);
}

void solve(){
    ll n, k, ans = 0;
    cin >> n >> k;
    ll l = (n + 1) >> 1, r = n;
    for (int i = l; i <= r; ++i){
        if (dep(n, i, 2) >= k) ans++;
    }
    cout << ans << endl;
}   

int main(){
    ios;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}