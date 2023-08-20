#include <bits/stdc++.h>
using namespace std;

struct edge{
    int v, next;
}e[6005];
int head[6005], f[6005][2], is_son[6005], vis[6005], n, ans, cnt;

void addedge(int u, int v){
    e[++cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void calc(int u){
    vis[u] = 1;
    for (int i = head[u]; i; i = e[i].next){
        if (vis[e[i].v]) continue;
        calc(e[i].v);
        f[u][1] += f[e[i].v][0];
        f[u][0] += max(f[e[i].v][1], f[e[i].v][0]);
    }
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> f[i][1];
    for (int i = 1, u, v; i < n; ++i){
        cin >> u >> v;
        is_son[u] = 1;
        addedge(v, u);
    }
    for (int i = 1; i <= n; ++i)
        if (!is_son[i]){
            calc(i);
            cout << max(f[i][1], f[i][0]) << endl;
        }
    return 0;
}