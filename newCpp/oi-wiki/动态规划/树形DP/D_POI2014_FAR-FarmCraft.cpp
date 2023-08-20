#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000010;
int n, cnt;
int val[maxn], head[maxn], f[maxn], siz[maxn], tmp[maxn];
struct edge{
    int to, nxt;
}e[maxn << 1];
inline bool cmp(int x, int y) {return siz[x] - f[x] < siz[y] - f[y];}

inline void add(int u, int v){
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}

void dfs(int x, int fa){
    if (x != 1) f[x] = val[x];
    for (int i = head[x]; i; i = e[i].nxt)
        if (e[i].to != fa) dfs(e[i].to, x);
    int tot = 0;
    for (int i = head[x]; i; i = e[i].nxt)
        if (e[i].to != fa) tmp[++tot] = e[i].to;
    sort(tmp + 1, tmp + tot + 1, cmp);
    for (int i = 1; i <= tot; ++i)
        f[x] = max(f[x], f[tmp[i]] + siz[x] + 1), siz[x] += siz[tmp[i]] + 2;
}

int main(){ 
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> val[i];
    for (int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs(1, 0);
    cout << max(f[1], siz[1] + val[1]);
    return 0;
}