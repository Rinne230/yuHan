#include <bits/stdc++.h>
using namespace std;
int f[305][305], s[305], n, m;//f[u][j]表示以u为根的子树中，已经遍历了u号点的前i棵子树，选了门课的最大学分
vector<int> g[305];

int dfs(int u){
    int siz = 1;
    f[u][1] = s[u];
    for (auto v : g[u]){
        int son = dfs(v);
        for (int i = min(siz, m + 1); i; --i)
            for (int j = 1; j <= son && i + j <= m + 1; ++j)
                f[u][i + j] = max(f[u][i + j], f[u][i] + f[v][j]);
        siz += son;
    }
    return siz;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        int k;
        cin >> k >> s[i];
        g[k].push_back(i);
    }
    dfs(0);
    cout << f[0][m + 1] << endl;
    return 0; 
}