#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int maxm = 105;
const int mod = 1e9 + 7;
typedef unsigned long long ull;
int n, m, sz[maxn], dp[maxn][maxm][2][2];//dp[ver][cnt][0/1][0/1]表示节点ver的子树中选出cnt个节点，其中选了/不选节点ver，ver是/否被覆盖的方案数量
int cnt, to[maxn << 1], nxt[maxn << 1], head[maxn << 1];
int cur[maxm][2][2];

inline void upd(int &a, int b){
    a += b, a -= (a >= mod ? mod : 0);
}

void addedge(int u, int v){
    to[++cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt;
}

void dfs(int u, int fa){
    sz[u] = 1;
    dp[u][0][0][0] = 1;
    dp[u][1][1][0] = 1;
    for (int i = head[u]; i; i = nxt[i]){
        int v = to[i];
        if (v == fa) continue;
        dfs(v, u);
        for (int j = 0; j <= min(m, sz[u]); ++j)
            for (int k = 0; k <= 1; k++)
                for (int l = 0; l <= 1; ++l)
                    cur[j][k][l] = dp[u][j][k][l], dp[u][j][k][l] = 0;;
        for (int j = 0; j <= min(m, sz[u]); ++j)
            for (int k = 0; k <= min(m, sz[v]) && j + k <= m; ++k){
                upd(dp[u][j + k][0][0], cur[j][0][0] * dp[v][k][0][1] % mod);
                upd(dp[u][j + k][0][1], (cur[j][0][0] * dp[v][k][1][1] + cur[j][0][1] * (dp[v][k][0][1] + dp[v][k][1][1])) % mod);
                upd(dp[u][j + k][1][0], cur[j][1][0] * (dp[v][k][0][0] + dp[v][k][0][1]) % mod);
                upd(dp[u][j + k][1][1], (cur[j][1][0] * (dp[v][k][1][0] + dp[v][k][1][1]) + cur[j][1][1] * (dp[v][k][0][0] + dp[v][k][1][0]) + cur[j][1][1] * (dp[v][k][0][1] + dp[v][k][1][1])) % mod);
            }
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1, u, v; i <= n - 1; ++i){
        cin >> u >> v;
        addedge(u, v);
        addedge(v, u);
    }
    dfs(1, 0);
    cout << (dp[1][m][0][1] + dp[1][m][1][1]) % mod << endl;
    return 0;
}