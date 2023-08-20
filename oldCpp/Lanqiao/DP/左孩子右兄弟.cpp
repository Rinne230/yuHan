#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, f[maxn];
vector<int> G[maxn];
void dfs(int u){//f[u] = 子节点数量 + 子树转化为二叉树后的最大高度
    f[u] = G[u].size();
    int maxv = 0;
    for (int i = 0; i < G[u].size(); ++i){
        int j = G[u][i];
        dfs(j);
        maxv = max(maxv, f[j]);
    }
    f[u] += maxv;
}
int main(){
    cin >> n;
    for (int i = 2, t; i <= n; ++i){
        cin >> t;
        G[t].push_back(i);
    }
    dfs(1);
    cout << f[1];
    return 0;
}