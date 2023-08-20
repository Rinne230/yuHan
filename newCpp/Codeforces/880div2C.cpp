#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    ll xx = 1, yy = 1, zz = 1;
    while (--a) {xx *= 10;}
    while (--b) {yy *= 10;}
    while (--c) {zz *= 10;}
    for (int i = xx; i < xx * 10; ++i) {
        ll x = max(yy, zz - i);
        ll y = min(yy * 10, zz * 10 - i);
        if (x > y) continue;
        if (y - x >= k) {
            cout << i << " + " << x + k - 1 << " = " << i + k - 1 + x << endl;
            return;
        }
        k -= y - x;
    }
    cout << -1 << endl;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}