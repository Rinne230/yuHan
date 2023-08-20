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
    ll n, tmp = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int u;
        cin >> u;
        if (u == i) tmp++;
    }
    cout << (tmp + 1) / 2 << endl;
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