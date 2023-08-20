#include <bits/stdc++.h>
using namespace std;
bool mp[101][101];
int cs[101][101];
int ans = 100;
int n, m;

void dfs(int cur, int cnt){
    if (cnt >= ans) return;
    if (cur > n) ans = cnt;
    else{
        for(int i = 1; i <= cnt; ++i){
            int k = 0;
            while (cs[i][k] && mp[cur][cs[i][k]] == 0) ++k;
            if (cs[i][k] == 0){
                cs[i][k] = cur;
                dfs(cur + 1, cnt);
                cs[i][k] = 0;
            }
        }
        cs[cnt + 1][0] = cur;
        dfs(cur + 1, cnt + 1);
        cs[cnt + 1][0] = 0;
    }
}
int main(){
    cin >> n;
    cin >> m;
    for (int i = 1, u, v; i <= m; ++i){
        cin >> u >> v;
        mp[u][v] = mp[v][u] = 1;
    }
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}