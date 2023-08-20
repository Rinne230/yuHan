#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int N = 1e5 + 10;
int a[N], cnt[N], calc[N], ans[N], len, n, m, q;
inline int read() {
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}
struct Query {
    int id, l, r, k;
    bool operator<(const Query &ver) {
        int j1 = r / len, j2 = ver.r / len;
        if (j1 != j2) return j1 < j2;
        else return l < ver.l;
    }
} query[N];

void add(int x) {
    calc[cnt[x]]-- ;
    cnt[x]++ ;
    calc[cnt[x]]++ ;
}
void del(int x) {
    calc[cnt[x]]-- ;
    cnt[x]-- ;
    calc[cnt[x]]++ ;
}
int main(void) {
    int t = 1;
    while (t--) {
        n = read();
        len = (int) sqrt(1.0 * n);
        for (int i = 1; i <= n; i++) 
            a[i] = read();
        m = read();
        for (int i = 0; i < m; i++) {
            int l, r, k;
            l = read(), r = read(), k = read();
            query[i] = {i, l, r, k};
        }
        sort(query, query + m);
        for (int i = 0, j = 1, z = 0; z < m; z++) {
            int l = query[z].l, r = query[z].r, k = query[z].k, id = query[z].id;
            while (i < r) add(a[++i]);
            while (i > r) del(a[i--]);
            while (j < l) del(a[j++]);
            while (j > l) add(a[--j]);
            ans[id] = calc[k];
        }
        for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
    }
    return 0;
}