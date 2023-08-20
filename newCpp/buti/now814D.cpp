#include <bits/stdc++.h>
using namespace std;
int x, T, n, a[5010], p[5010][5010], f[5010][5010], t, ans, s, b[5010];
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)
        {
            t = 0;
            p[i][0] = i; // 第j个小于i的位置
            for (int j = i; j <= n; j++)
                if (a[i] > a[j])
                {
                    t++;
                    p[i][t] = j;
                }
            while (t <= n + 1)
            {
                t++;
                p[i][t] = n + 1;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            f[i][i] = 0; // f[i][j]  j~i有多少比i小的
            for (int j = i - 1; j >= 1; j--)
            {
                if (a[j] < a[i])
                    f[i][j] = f[i][j + 1] + 1;
                else
                    f[i][j] = f[i][j + 1];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            s = 0;
            for (int j = i; j <= n; j++)
                b[j] = 0;
            for (int j = i; j <= n; j++)
            {
                x = j - i - f[j][i];//多少个比a[j]大的 
                b[p[j][x]]++;
                b[p[j][x + 1]]--;
                s = s + b[j];
                if (s == 0)
                    ans++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}