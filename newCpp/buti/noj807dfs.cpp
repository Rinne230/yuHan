/**
 * @file [USACO 2011 Nov S]Cow Beauty Pageant
 * @author atrilactose (2307767173@qq.com)
 * @brief http://oj.ecustacm.cn/problem.php?id=1868 
 * @version 0.1
 * @date 2023-08-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
char mp[51][51];
ll col[51][51];
ll tox[4] = {-1, 0, 1, 0};
ll toy[4] = {0, -1, 0, 1};
ll dis[4][4];
ll disP[51][51][4];
ll n, m;

int main()
{
    ios;
    vector<tll> edge;
    function<void(int, int, int)> dfs1 = [&](int x, int y, int c)
    {
        col[x][y] = c;
        for (int i = 0; i < 4; ++i)
        {
            int tx = x + tox[i], ty = y + toy[i];
            if (tx < 1 || tx > n || ty < 1 || ty > m)
                continue;
            if (mp[tx][ty] == '.' && mp[x][y] == 'X')
                edge.push_back({x, y, col[x][y]});
            if (mp[tx][ty] == '.' || col[tx][ty])
                continue;
            col[tx][ty] = c;
            dfs1(tx, ty, c);
        }
    };
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j)
            dis[i][j] = maxn;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        disP[i][j][1] = disP[i][j][2] = disP[i][j][3] = maxn;
    ll cnt = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> mp[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (mp[i][j] == 'X' && !col[i][j])
                dfs1(i, j, ++cnt);

    for (int i = 0; i < edge.size(); ++i){
        for (int j = i + 1; j < edge.size(); ++j){
            auto [x1, y1, c1] = edge[i];
            auto [x2, y2, c2] = edge[j];
            if (c1 == c2) continue;
            dis[c1][c2] = dis[c2][c1] = min(dis[c1][c2], max(0ll, abs(x1 - x2) + abs(y1 - y2) - 1));
        }
    }
    ll ans = maxn;
    for (int i = 1; i <= 3; ++i){
        for (int j = 1; j <= 3; ++j){
            for (int k = 1; k <= 3; ++k){
                if (i == j || j == k || i == k) continue;
                if (dis[i][j] + dis[i][k] < ans) ans = dis[i][j] + dis[i][k];
            }
        }
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (col[i][j]) continue;
            for (int k = 0; k < edge.size(); ++k){
                auto [x, y, c] = edge[k];
                disP[i][j][c] = min(disP[i][j][c], max(0ll, abs(x - i) + abs(y - j)) - 1);
            }
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            ll res = 1;
            if (col[i][j]) continue;
            for (int k = 1; k <= 3; ++k)
                res += disP[i][j][k];
            ans = min(ans, res);
        }
    }
    cout << ans << endl;
    return 0;
}