#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
ll head[maxn], nxt[maxn], to[maxn], val[maxn], cnt = 0;
ll f[maxn];

void solve(){
    function<void(int, int, int)> addedge = [&](int u, int v, int w){
        to[++cnt] = v;
        val[cnt] = w;
        nxt[cnt] = head[u];
        head[u] = cnt;
    };
    function<void(int, int)> dfs = [&](int u, int fa){
        bool flag = 0;
        for (int i = head[u]; i; i = nxt[i]){
            int v = to[i];
            if (v == fa) continue;
            dfs(v, u);
            f[u] += min(f[v], val[i]);
            flag = 1;
        }
        if (!flag) f[u] = 0x7fffffff;
    };
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        addedge(u, v, w);
        addedge(v, u, w);
    }
    dfs(s, 0);
    cout << f[s] << endl;
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