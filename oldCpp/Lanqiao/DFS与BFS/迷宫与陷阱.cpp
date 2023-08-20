#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char g[N][N];
bool st[N][N][12];
int n, k;
int to[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
struct node{
    int x, y, k, step;
};

int bfs(){
    queue<node> q;
    memset(st, 0, sizeof(st));
    q.push({1, 1, 0, 0});
    st[1][1][0] = true;
    while(!q.empty()){
        node temp = q.front();
        q.pop();
        if (temp.x == n && temp.y == n) return temp.step;
        for (int i = 0; i < 4; ++i){
            int tx = temp.x + to[i][0], ty = temp.y + to[i][1];
            if (tx < 1 || ty < 1 || tx > n || ty > n || g[tx][ty] == '#') continue;
            if (g[tx][ty] == '%' && st[tx][ty][temp.k] == 0){
                g[tx][ty] = '.';
                st[tx][ty][k] = true;
                q.push({tx, ty, k, temp.step + 1}); 
            }
            if (g[tx][ty] == 'X' && temp.k && st[tx][ty][temp.k - 1] == 0){
                st[tx][ty][temp.k - 1] = true;
                q.push({tx, ty, temp.k - 1, temp.step + 1});
            }
            if (g[tx][ty] == '.' && temp.k && st[tx][ty][temp.k - 1] == 0){
                st[tx][ty][temp.k - 1] = true;
                q.push({tx, ty, temp.k - 1, temp.step + 1});
            }
            if (g[tx][ty] == '.' && !temp.k && st[tx][ty][0] == 0){
                st[tx][ty][0] = true;
                q.push({tx, ty, 0, temp.step + 1});
            }
        }
    }
    return -1;
}
int main(){
    while (cin >> n >> k){
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                cin >> g[i][j];
        cout << bfs() << endl;
    }
    return 0;
}