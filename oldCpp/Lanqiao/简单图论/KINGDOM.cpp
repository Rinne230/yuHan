#include <bits/stdc++.h>
#define inf 999999999999
#define maxn 300005
using namespace std;
typedef long long ll;
int n, m;
ll dis[maxn], head[maxn << 1], to[maxn << 1], val[maxn << 1], nxt[maxn << 1], cnt;
bool vis[maxn];
void addedge(ll u, ll v, ll w){
    to[++cnt] = v;
    val[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt;
}
// void Dijkstra(){
//     for (int i = 1; i <= n; ++i) dis[i] = inf;
//     dis[1] = 0;
//     dis[0] = inf;
//     while (true){
//         int u = 0;
//         for (int i = 1; i <= n; ++i)
//             if (!vis[i] && dis[u] > dis[i]) u = i;
//         if (u == 0) break;
//         vis[u] = 1;
//         for (int i = head[u]; i; i = nxt[i]){
//             dis[to[i]] = min(dis[u] + val[i], dis[to[i]]);
//         }
//     }
// }
struct node{
    ll v, w;
    friend bool operator < (node a, node b){
        return a.w > b.w;
    }
}tmp;
priority_queue<node> q;
void Dijkstra(){
    for (int i = 1; i <= n; ++i) dis[i] = inf;
    dis[1] = 0;
    tmp.v = 1, tmp.w = 0, q.push(tmp);
    while (!q.empty()){
        int u = q.top().v;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = nxt[i])
            if (dis[to[i]] > (ll)dis[u] + val[i]){
                dis[to[i]] = dis[u] + val[i];
                tmp.w = dis[to[i]], tmp.v = to[i];
                q.push(tmp);
            }
    }
}
int main(){
    cin >> n >> m;
    for (ll i = 1, u, v, w; i <= m; ++i){
        cin >> u >> v >> w;
        addedge(u, v, w);
    }
    Dijkstra();
    for (int i = 1; i <= n; ++i) {
        if (dis[i] == inf) cout << -1 << " ";
        else cout << dis[i] << " ";
    }
}