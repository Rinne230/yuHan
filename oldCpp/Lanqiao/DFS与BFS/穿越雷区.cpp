#include <bits/stdc++.h>
using namespace std;
char mp[101][101];
bool vis[101][101];
int ans = 0x7fffffff, n;
int to[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
struct node{
    int x, y, step;
};

void bfs(int x, int y){
    queue<node> q;
    node st, temp;
    st.x = x, st.y = y;
    st.step = 0;
    q.push(st);
    while (!q.empty()){
        temp = q.front();
        q.pop();
        if (mp[temp.x][temp.y] == 'B'){ 
            cout << temp.step << endl;
            return;
        }
        node nxt;
        for (int i = 0; i < 4; ++i){
            int tx = temp.x + to[i][0], ty = temp.y + to[i][1];
            if (tx < 0 || ty < 0 || tx >= n || ty >= n || vis[tx][ty] || mp[tx][ty] == mp[temp.x][temp.y]) continue;
            nxt.x = tx;
            nxt.y = ty;
            nxt.step = temp.step + 1;
            vis[tx][ty] = 1;
            q.push(nxt);
        }
    }
}
int main(){
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> mp[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= n; ++j)
           if (mp[i][j] == 'A')
                bfs(i, j);
    return 0;
}