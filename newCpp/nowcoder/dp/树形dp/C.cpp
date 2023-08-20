/**
 * @file 数的最小覆盖点
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-07-27
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
#define endl '\n'
#define mset(s, _) memset(s, _, sizeof(s))
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int N = 4e3 + 10, mod = 1e9 + 7;
int n, m;
int h[N], nex[N], v[N], idx;
void add(int a, int b) {
    v[idx] = b; nex[idx] = h[a]; h[a] = idx ++ ;
}

int f[N][5], st[N];
void init() {
    mset(h, -1); mset(f, 0); mset(st, 0); idx = 0;
}

void dp(int u) {
    bool fg = 0;
    for(int i = h[u]; ~i; i = nex[i]) {
        int j = v[i];
        fg = 1;
        dp(j);
        f[u][0] += f[j][1];
        f[u][1] += min(f[j][0], f[j][1]);
    }
    f[u][1] += 1;
    if(!fg) {
        f[u][0] = 0; f[u][1] = 1;
    }
}

int main() {
    while(cin >> n) {
        init();
        rep(i, 1, n) {
            int a, num, b; char t;
            cin >> a >> t >> t >> num >> t;
            rep(j, 1, num) {
                cin >> b; add(a, b); st[b] = 1;
            }
        }
        int root = 0;
        while(st[root]) root ++ ;
        dp(root);
        cout << min(f[root][1], f[root][0]) << endl;
    }

    return 0;
}