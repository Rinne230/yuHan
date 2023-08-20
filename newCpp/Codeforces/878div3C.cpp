#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int a[N];
void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    ll res = 0;
    ll cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] <= q) {
            cnt++;
        } else {
            if (cnt >= k) {
                res += ((cnt - k + 1) * (cnt - k + 2)) / 2;
            }
            cnt = 0;
        }
    }
    if (cnt >= k) {
        res += ((cnt - k + 1) * (cnt - k + 2)) /2;
    }
    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
