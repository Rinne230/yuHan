#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5 + 10;
const int MOD = 1e9 + 7;
ll dp1[N], dp2[N], max_[N], min_[N];

void solve() {
    int n;
    cin >> n;
    int idx = 1;
    char op;
    dp2[1] = 1;
    max_[1] = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> op;
        if (op == '+') {
            ll u, x;
            cin >> u >> x;
            dp1[++idx] = min(dp1[u] + x, x);
            dp2[idx] = max(dp2[u] + x, x);
            max_[idx] = max(dp2[idx], max_[u]);
            min_[idx] = min(dp1[idx], min_[u]);
        } else if (op == '?') {
            ll u, v, k;
            cin >> u >> v >> k;
            cout << (k <= max_[v] && k >= min_[v] ? "YES" : "NO") << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}