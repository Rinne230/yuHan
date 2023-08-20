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
    int n, m;
    function<void(int, int, int)> addedge = [&](int u, int v, int w){
        to[++cnt] = v;
        val[cnt] = w;
        nxt[cnt] = head[u];
        head[u] = cnt;
    };
    function<void(int, int, int)> dfs = [&](int u, int fa, int mid){
        f[u] = 0;
        bool flag = 0;
        for (int i = head[u]; i; i = nxt[i]){
            int v = to[i];
            if (v == fa) continue;
            dfs(v, u, mid);
            if (val[i] <= mid)f[u] += min(f[v], val[i]);
            else f[u] += f[v];
            flag = 1;
        }
        if (!flag) f[u] = 0x7fffffff;
    };
    function<bool(int)> check = [&](int mid){
        dfs(1, 0, mid);
        return f[1] <= m;
    };
    cin >> n >> m;
    for (int i = 1; i <= n - 1; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        addedge(u, v, w);
        addedge(v, u, w);
    }
    int l = 0, r = m + 1;
    while (l < r){
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    if (r == m + 1) r = -1; 
    cout << r << endl;
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