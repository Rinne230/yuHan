/**
 * @file 树上背包(最多切q条边，剩下多少东西)
 * @author atrilactose
 * @brief
 * @version 0.1
 * @date 2023-07-28
 *
 * @copyright Copyright (c) 2023
 *
 */
    #include <bits/stdc++.h>
    using namespace std;
    const int N = 105;
    int dp[N][N];//dp[i][j]以i为根的子树保留j个分支可以得到的最大的苹果数量 
    int h[N], e[N << 1], nx[N << 1], w[N << 1];
    int cnt = 1;
    void add(int a, int b, int v)
    {
        e[cnt] = b;
        w[cnt] = v;
        nx[cnt] = h[a];
        h[a] = cnt++;
    }
    int n, q;
    void dfs(int u, int f)
    {
        for (int i = h[u]; i; i = nx[i])
        {
            int v = e[i];
            if (v != f)
            {
                dfs(v, u);
                for (int j = q; j >= 1; j--)
                {
                    for (int k = 0; k <= j - 1; k++)
                    {
                        dp[u][j] = max(dp[u][j], dp[u][k] + w[i] + dp[v][j - k - 1]);
                    }
                }
            }
        }
    }
    int main()
    {

        cin >> n >> q;
        int a, b, v;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a >> b >> v;
            add(a, b, v);
            add(b, a, v);
        }
        dfs(1, -1);
        cout << dp[1][q];
    }