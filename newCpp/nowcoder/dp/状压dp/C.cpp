/**
 * @file TSP
 * @author atrilactose
 * @brief
 * @version 0.1
 * @date 2023-07-31
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
const int inf = 0x3fffffff;
int e[maxn][maxn], dis[maxn][maxn], nod[50];
int dp[50005][maxn];
void work()
{
    memset(dis, 0x3f, sizeof dis);
    memset(dp, 0x3f, sizeof dp);
    int n, m, r, x, y, z;
    cin >> n >> m >> r;
    for (int i = 0; i < r; i++)
        cin >> nod[i], nod[i]--;//所有要经过的点
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> z;
        x--;
        y--;
        dis[x][y] = dis[y][x] = e[x][y] = e[y][x] = z;
    }
    for (int i = 0; i < n; i++)
        dis[i][i] = 0;
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    for (int i = 0; i < r; i++)
        dp[(1 << i)][nod[i]] = 0;
    for (int sta = 0; sta < 1 << r; sta++)
    {
        for (int j = 0; j < r; j++)
        {
            if ((sta >> j) & 1)
            {
                for (int k = 0; k < r; k++)
                    if ((sta >> k) & 1)
                        dp[sta][nod[j]] = min(dp[sta ^ (1 << j)][nod[k]] + dis[nod[k]][nod[j]], dp[sta][nod[j]]);
            }
        }
    }
    int res = inf;
    for (int i = 0; i < r; i++)
        res = min(res, dp[(1 << r) - 1][nod[i]]);
    cout << res << endl;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t = 1;
    // cin>>t;
    while (t--)
        work();
    return 0;
}