#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
ll f[maxn], d[maxn];
int n, m, q;
ll s;

int find(int x){
    if (x == f[x]) return x;
    int root = find(f[x]);
    d[x] += d[f[x]];
    return f[x] = root;
}

void merge(int u, int v, ll w) {
    int x = find(u);
    int y = find(v);
    if (x == y) return;
    f[x] = y;
    d[x] = w + d[v] - d[u];
}

int main(){
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) f[i] = i;
    for (int i = 1; i <= m; ++i){
        int l, r;
        cin >> l >> r >> s;
        merge(l - 1, r, s);
    }
    for (int i = 1; i <= q; ++i){
        int l, r;
        cin >> l >> r;
        if (find(l - 1) != find(r)) cout << "UNKNOWN" << endl;
        else cout << d[l - 1] - d[r] << endl;
    }
    return 0;
}