#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
ll w[N];
ll f[N][3]; // 记得初始化
int idx, e[N], ne[N], h[N];
void add(int a, int b)
{
    e[idx] = a;
    ne[idx] = h[b];
    h[b] = idx++;
}
void dfs(int u, int fa)
{
    f[u][0] = 0;
    f[u][1] = 1e9;
    f[u][2] = w[u];
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == fa)
            continue;
        dfs(j, u);
        f[u][0] += min(f[j][1], f[j][2]);
        f[u][2] += min(min(f[j][0], f[j][1]), f[j][2]);
    }
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == fa)
            continue;

        f[u][1] = min(f[u][1], f[u][0] + f[j][2] - min(f[j][1], f[j][2]));
    }
}

void solve()
{
    idx = 0;
    int n;
    cin >> n;
    for (int i = 0; i <= n * 2; i++)
        h[i] = -1;
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);
    cout << min(f[1][2], f[1][1]) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}