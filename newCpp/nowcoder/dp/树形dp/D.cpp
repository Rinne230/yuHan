/**
 * @file 树的最小支配集
 * @author atrilactose
 * @brief
 * @version 0.1
 * @date 2023-07-27
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define N 10010

int n;
int e[N * 2], ne[N * 2], h[N], idx = 0;
int f[N][3];
/***
 * f[i][0]选i且i及i的子树都被覆盖了
 * f[i][1]不选i且i被其儿子覆盖
 * f[i][2]不选i且i被其父亲覆盖(儿子可选可不选)
*/
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int pre)
{
    f[u][0] = 1, f[u][1] = f[u][2] = 0;
    bool flag = true;
    int tmp = 0x3f3f3f3f;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int v = e[i];
        if (v == pre)
            continue;
        dfs(v, u);
        f[u][2] += min(f[v][1], f[v][0]);
        f[u][0] += min(min(f[v][0], f[v][1]), f[v][2]);
        if (f[v][0] <= f[v][1])
        {
            flag = false;
            f[u][1] += f[v][0];
        }
        else
        {
            f[u][1] += f[v][1];
            tmp = min(tmp, f[v][0] - f[v][1]);
        }
    }
    if (flag)
        f[u][1] += tmp;
}

int main()
{
    memset(f, 0x3f, sizeof f);
    memset(h, -1, sizeof h);

    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    dfs(1, -1);

    int ans = min(f[1][0], f[1][1]);

    cout << ans << endl;

    return 0;
}