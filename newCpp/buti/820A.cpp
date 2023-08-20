#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define rep(i, j, k) for(int i = (j); i <= (k); i++)
#define per(i, j ,k) for(int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 105;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

ll dis[maxn][maxn];
bool vis[maxn];
ll d[maxn];

void solve(){
    int n;
    cin >> n;
    fill(dis, dis + 101 * 101, inf);
    fill(d, d + n + 1, inf);
    d[1] = 0;
    for (int i = 0; i < n * (n - 1) / 2; ++i){
        int u, v, w, op;
        cin >> u >> v >> w >> op;
        if (op == 1) w = 0;
        dis[u][v] = dis[v][u] = w;
    }
    ll ans = 0;
    while(true){
        int v = -1;
        for (int i = 1; i <= n; ++i){
            if (vis[i] == 0 && (v == -1 || d[v] > d[i])) v = i;
        }
        if (v == -1) break;
        vis[v] = 1;
        ans += d[v];
        for (int i = 1; i <= n; ++i){
            if(d[i] > dis[i][v]) d[i] = dis[i][v];
        }
    }
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