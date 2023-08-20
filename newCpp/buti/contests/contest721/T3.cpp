#include<bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;

void solve(){
    ll n;
    ll r, g, b;
    cin >> n;
    cin >> r >> g >> b;
    if (n & 1) cout << "Bob" << endl;
    else cout << "Alice" << endl;
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
