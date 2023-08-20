#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 4e5 + 10;
const int MOD = 1e9 + 7;

vector<int> g[N];
ll dp[N];

void dfs(int u, int rt) {
    if (g[u].size() == 1 && u != 1) {
        dp[u] = 1;
    }
    for (int i : g[u]) {
        if (i != rt) {
            dfs(i, u);
            dp[u] += dp[i];
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        g[i].clear();
        dp[i] = 0;
    }
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += g[i].size();
    }
    dfs(1, 0);
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << dp[x] * dp[y] << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}