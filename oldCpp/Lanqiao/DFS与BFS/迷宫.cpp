#include <bits/stdc++.h>
using namespace std;
char a[31][51];
char d[4] = {'D', 'L', 'R', 'U'};
int to[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
int dis[31][51];
void bfs(){
    queue<pair<int, int>> q;
    memset(dis, -1, sizeof(dis));
    dis[30][50] = 0;
    q.push({30, 50});
    while(!q.empty()){
        pair<int, int> tmp = q.front();
        q.pop();
        for (int i = 0, tx, ty; i < 4; ++i){
            tx = tmp.first + to[i][0];
            ty = tmp.second + to[i][1];
            if (tx > 0 && ty > 0 && tx <= 30 && ty <= 50 && a[tx][ty] == '0' && dis[tx][ty] == -1){
                dis[tx][ty] = dis[tmp.first][tmp.second] + 1;
                q.push({tx, ty});
            }
        }
    }
}
int main(){
    for (int i = 1; i <= 30; ++i)
        for (int j = 1; j <= 50; ++j) 
            cin >> a[i][j];
    bfs();
    int x = 1, y = 1;
    string ans;
    while (x != 30 || y != 50){
        for (int i = 0, tx, ty; i < 4; ++i){
            tx = x + to[i][0];
            ty = y + to[i][1];
            if (tx > 0 && ty > 0 && tx <= 30 && ty <= 50 && a[tx][ty] == '0' && dis[tx][ty] == dis[x][y] - 1){
                x = tx, y = ty;
                ans = ans + d[i];
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}