/**
 * @file 炮兵阵地状压dp
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
#define int long long
int dp[2][1050][1050];//第i行的状态为j,i - 1行的状态数为k
char mp[105][105];
int way[105];
int lowbit(int x)
{
    return x & (-x);
}
bool check1(int x)
{
    if (x & (x << 1ll))
        return 0;
    if (x & (x << 2ll))
        return 0;
    if (x & (x >> 1ll))
        return 0;
    if (x & (x >> 2ll))
        return 0;
    return 1;
}
int coun[1050];//当前行状态为i的方案数
void count()
{
    for (int i = 0; i <= 1030; i++)
    {
        int x = i;
        int cnt = 0;
        while (x)
        {
            if (x & 1)
                cnt++;
            x /= 2;
        }
        coun[i] = cnt;
    }
}
bool check(int x, int y)
{
    if (x & y)
        return 0;
    return 1;
}
signed main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int cnt = (1ll << m) - 1;
    count();
    for (int i = 1; i <= n; i++)
    {
        int x = 0;
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
            x <<= 1;
            if (mp[i][j] == 'H')
            {
                x |= 1;
            }
        }
        way[i] = x;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= cnt; j++)
            for (int k = 0; k <= cnt; k++)
            {
                dp[0][j][k] = dp[1][j][k];
            }
        for (int j = 0; j <= cnt; j++)
        {
            if (way[i] & j)
                continue;
            if (check1(j) == 0)
                continue;
            for (int k = 0; k <= cnt; k++)
            {
                if (check1(k) == 0)
                    continue;
                if (check(j, k) == 0)
                    continue;
                for (int l = 0; l <= cnt; l++)
                {
                    if (check1(l) == 0)
                        continue;
                    if (check(j, l) == 0)
                        continue;
                    dp[1][j][k] = max(dp[1][j][k], dp[0][k][l] + coun[j]);
                    ans = max(ans, dp[1][j][k]);
                }
            }
        }
    }
    cout << ans;
}