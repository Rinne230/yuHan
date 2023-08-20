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
    int cnt = 0;
    cin >> n;
    for (int i = 1, x; i <= n; ++i){
        cin >> x;
        if (x & 1) cnt++;
    }
    if (cnt & 1) cout << "NO" << endl;
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