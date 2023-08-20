#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0}; // 上下左右
int dy[4] = {0, 1, 0, -1};
struct Point
{
    int x, y, h; // 坐标xy、高度h
    Point(int x_, int y_, int h_)
    {
        x = x_;
        y = y_;
        h = h_;
    };
    bool operator<(const Point &r) const { return (h < r.h); }
};
int n, m;
int a[505][505];
bool done[505][505]; // done[x][y]=1表示(x,y)已经淹没
void floodfill(int x, int y)
{                      // “洪水填充”，平流或往下流
    done[x][y] = true; // 标记为淹没
    for (int i = 0; i < 4; i++)
    { // 扩散周围与它等高或矮的点
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n || done[nx][ny])
            continue;
        if (a[nx][ny] <= a[x][y])
            floodfill(nx, ny); // 继续“洪水填充”
    }
}
int main()
{
    cin >> n >> m;
    priority_queue<Point> Q; // 优先队列，队首的h最大
    for (int j = 0; j < n; j++)
        for (int i = 0; i < m; i++)
        {
            cin >> a[i][j];
            done[i][j] = (a[i][j] <= 1); // 0和1标记为已经淹没
            if (a[i][j] > 1)
                Q.push(Point(i, j, a[i][j])); // 把点放进优先队列
        }
    int ans = 0;
    while (!Q.empty())
    {
        Point p = Q.top(); // 每次取出剩下的最高点
        Q.pop();
        if (!done[p.x][p.y])
        {                        // 如果它没有淹没过，就“洪水填充”
            ans++;               // 这次倒水相当于建设了一部电梯
            floodfill(p.x, p.y); // “洪水填充”
        }
    }
    cout << ans << endl;
    return 0;
}
