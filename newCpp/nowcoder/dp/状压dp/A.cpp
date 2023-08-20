/**
 * @file 互不侵犯
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
#define ll long long
#define PII pair<int, int>
#define inf 0x3f3f3f
const int N = 2005, mod = 998244353;
vector<int> g[N];
ll f[10][2000][100], cnt[2000], ok[2000];//cnt[i]表示i状态的国王数
ll n, k;
int main()
{
    scanf("%lld%lld", &n, &k);
    int x = (1 << n) - 1;
    int tot = 0;
    for (int j = 0; j <= x; j++)
    {
        if ((j << 1) & j)
            continue;
        int s = 0, t = j;
        while (t)
        {
            if (t & 1)
                s++;
            t >>= 1;
        }
        cnt[j] = s;
        ok[++tot] = j;
        f[1][j][s] = 1;//前i行状态为j且放了k个国王
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= tot; j++)
        {
            int s1 = ok[j];
            for (int l = 1; l <= tot; l++)
            {
                int s2 = ok[l];
                if (((s2 | (s2 << 1) | (s2 >> 1)) & s1) == 0)
                {
                    for (int m = cnt[s1]; m <= k; m++)
                    {
                        f[i][s1][m] += f[i - 1][s2][m - cnt[s1]];//第i行状态为s1一共放了m个,第i行放了cnt[s1]个
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= tot; i++)
        ans += f[n][ok[i]][k];
    printf("%lld", ans);
}