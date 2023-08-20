/**
 * @file 树的直径
 * @author atrilactose
 * @brief 
 * @version 0.1
 * @date 2023-07-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
vector<ll> G[maxn];
ll w[maxn], dis[maxn], ans = -1e18;

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> w[i];
    }
    for (int i = 1; i <= n - 1; ++i){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    function<void(int, int)> dfs = [&](int u, int fa){
        ll tmp = 0, mx1 = 0, mx2 = 0;
        for (auto v: G[u]){
            if (v == fa) continue;
            dfs(v, u);
            tmp = dis[v];
            if (tmp >= mx1){
                mx2 = mx1;
                mx1 = tmp;
            }else if (tmp >= mx2){
                mx2 = tmp;
            }
        }
        ans = max(ans, mx1 + mx2 + w[u]);
        dis[u] = mx1 + w[u];
    };
    dfs(1, 0);
    cout << ans << endl;
}

int main(){
    ios;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}