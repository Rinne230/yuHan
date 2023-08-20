#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9 + 5;
ll n, m, q;
ll dis[501][501];
int main(){
    cin >> n >> m >> q;
    for (ll i = 1; i <= n; ++i)
        for (ll j = 1; j <= n; ++j)
            if (i != j)
                dis[i][j] = inf;
    for (ll i = 1, u, v, w; i <= m; ++i){
        cin >> u >> v >> w;
        dis[u][v] = dis[v][u] = min(dis[u][v], w);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= n; ++k)
                if (dis[i][j] > dis[i][k] + dis[k][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
    for (ll i = 1, u, v; i <= q; ++i){
        cin >> u >> v;
        if (dis[u][v] > 1e9 + 4)
            cout << -1 << endl;
        else 
            cout << dis[u][v] << endl;
    }
    return 0;
}