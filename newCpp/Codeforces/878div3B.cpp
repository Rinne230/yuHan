#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n, k;
    cin >> n >> k;
    k = k > 30 ? 30 : k;
    cout << min(n + 1, (ll)(1 << k)) << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}