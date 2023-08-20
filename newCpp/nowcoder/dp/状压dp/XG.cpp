#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL mod = 1e9 + 7;
int INF = 0x3f3f3f3f;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> G(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++)
            G[i][i] = 0;
        for (int i = 1; i <= m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            a--;
            b--;
            G[a][b] = G[b][a] = min(G[a][b], c);
        }
        vector<vector<int>> f((1 << n), vector<int>(n, INF));
        vector<int> g((1 << n), 0);
        for (int i = 1; i < (1 << n); i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i >> j & 1)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if (G[j][k] != INF)
                        {
                            g[i] |= (1 << k);//g[i]表示可以到达的状态
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
            f[1 << i][0] = 0;
        for (int i = 1; i < (1 << n); i++)
        {
            for (int j = i; j; j = i & (j - 1))
            {
                if ((g[j] | i) == g[j])
                {
                    int s = j ^ i;
                    int res = 0;
                    for (int k = 0; k < n; k++)
                    {
                        if (s >> k & 1)
                        {
                            int cost = INF;
                            for (int l = 0; l < n; l++)
                            {
                                if (l == k)
                                    continue;
                                if (j >> l & 1)
                                {
                                    cost = min(cost, G[k][l]);
                                }
                            }
                            res += cost;
                        }
                    }
                    for (int k = 1; k < n; k++)
                    {
                        f[i][k] = min(f[i][k], f[j][k - 1] + res * k);//f[s][i]表示s状态的所有点全都属于前i层
                    }
                }
            }
        }
        int res = INF;
        for (int i = 0; i < n; i++)
        {
            res = min(res, f[(1 << n) - 1][i]);
        }
        cout << res << endl;
        // cout << f[(1 << n) - 1][2] << endl;
    }
    return 0;
}