#include <bits/stdc++.h>
using namespace std;
int to[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
bool mp[4][4];
int ans;

void dfs(int x, int y, int cur){
    if (cur == 15){
        ans++;
        return;
    }
    for (int i = 0; i < 4; ++i){
        int tx = x + to[i][0];
        int ty = y + to[i][1];
        if (tx < 0 || tx > 3 || ty < 0 || ty > 3 || mp[tx][ty]) continue;
        mp[tx][ty] = 1;
        dfs(tx, ty, cur + 1);
        mp[tx][ty] = 0;
    }                  
}

int main(){
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j){
            mp[i][j] = 1;
            dfs(i, j, 0);
            mp[i][j] = 0;
        }
    cout << ans << endl;
    return 0;
}