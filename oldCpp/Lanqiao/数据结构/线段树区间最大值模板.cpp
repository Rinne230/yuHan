#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000;

int n, m;
int a[MAXN+5];

struct Node {
    int l, r;
    int maxn;
}tr[MAXN*4+5];

void pushup(int u) {
    tr[u].maxn = max(tr[u<<1].maxn, tr[u<<1|1].maxn);
}

void build(int u, int l, int r) {
    if (l == r) {
        tr[u] = {l, r, a[l]};
        return;
    }
    tr[u] = {l, r};
    int mid = (l + r) >> 1;
    build(u<<1, l, mid);
    build(u<<1|1, mid+1, r);
    pushup(u);
}

void modify(int u, int x, int c) {
    if (tr[u].l == x && tr[u].r == x) {
        tr[u].maxn = c;
        return;
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (x <= mid) modify(u<<1, x, c);
    else modify(u<<1|1, x, c);
    pushup(u);
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].maxn;
    int mid = (tr[u].l + tr[u].r) >> 1;
    int res = INT_MIN;
    if (l <= mid) res = max(res, query(u<<1, l, r));
    if (r > mid) res = max(res, query(u<<1|1, l, r));
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build(1, 1, n);
    while (m--) {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1) modify(1, x, y);
        else printf("%d\n", query(1, x, y));
    }
    return 0;
}
