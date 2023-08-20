#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 1e6 + 5;
const int M = 2e6 + 6;
int n;
int h[N], num, ne[M], to[M];
LL depth[N], si[N];
LL f[N], ans;
void add(int a, int b)
{
    ne[num] = h[a], to[num] = b, h[a] = num++;
}
void dfs1(int u, int fa)
{
    f[u] = depth[u];
    si[u] = 1;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = to[i];
        if (j == fa)
            continue;
        depth[j] = depth[u] + 1;
        dfs1(j, u);
        f[u] += f[j];
        si[u] += si[j];
    }
    return;
}
void dfs2(int u, int fa)
{
    ans = min(ans, f[u]);
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = to[i];
        if (j == fa)
            continue;
        f[j] = f[u] - si[j] * 2 + n;
        dfs2(j, u);
    }
    return;
}
int main()
{
    scanf("%d", &n);
    memset(h, -1, sizeof(h));
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v), add(v, u);
    }
    dfs1(1, 0);
    ans = f[1];
    dfs2(1, 0);
    printf("%d\n", ans);
    return 0;
}