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
    for (int i = 1; i <= n; ++i){
        if (n % i != 0){    
            cout << i - 1 << endl;
            return;
        } 
    }
    cout << n << endl;
    return;
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