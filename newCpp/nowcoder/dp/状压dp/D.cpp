/**
 * @file 简单环
 * @author atrilactose
 * @brief 
 * @version 0.1
 * @date 2023-07-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 998244353;
const int maxn = 25;
ll ans[maxn], dp[1 << 20][maxn], num[1 << 20];
int n, m, k;
bool vis[maxn][maxn];
ll ksm(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a % MOD;
    ll mid = ksm(a, b >> 1);
    if (b & 1)
        return mid * mid % MOD * a % MOD;
    else
        return mid * mid % MOD;
}
void Init()
{
    for (int st = 0; st < (1 << n); st++)
    {
        int cur = st, cnt = 0;
        while (cur)
        {
            if (cur & 1)
                cnt++;
            cur >>= 1;
        }
        num[st] = cnt;
    }
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    Init();
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        vis[u][v] = true, vis[v][u] = true;
    }
    for (int i = 1; i <= n; i++)
        dp[1 << (i - 1)][i] = 1;
    for (int st = 1; st < (1 << n); st++)
    {
        int lowbit = st & (-st), s = 0;
        while (lowbit)
            s++, lowbit >>= 1;
        for (int j = 1; j <= n; j++)
            if (dp[st][j])
            {
                if (vis[j][s] && num[st] > 2)
                    ans[num[st] % k] = (ans[num[st] % k] + dp[st][j]) % MOD;
                for (int k = s + 1; k <= n; k++)
                    if ((st & (1 << (k - 1))) == 0 && vis[j][k])
                    {
                        int p = st | (1 << (k - 1));
                        dp[p][k] = (dp[p][k] + dp[st][j]) % MOD;
                    }
            }
    }
    ll invtwo = ksm(2, MOD - 2);
    for (int i = 1; i <= k; i++)
        cout << ans[i - 1] * invtwo % MOD << endl;
    return 0;
}