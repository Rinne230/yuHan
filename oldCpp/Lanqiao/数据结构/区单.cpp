#include <bits/stdc++.h>
using namespace std;
int tree[500010], y[500010];
int n, m;
int lowbit(int x) { return x & -x; }
void add(int x, int k)
{
    while (x <= n)
    {
        tree[x] += k;
        x += lowbit(x);
    }
}
int sum(int x)
{
    int ans = 0;
    while (x != 0)
    {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> y[i];
    for (int i = 1; i <= m; i++)
    {
        int u, a, b, c, v;
        cin >> u;
        if (u == 1)
        {
            cin >> a >> b >> c;
            add(a, c);
            add(b + 1, -c);
        }
        else if (u == 2)
        {
            cin >> v;
            cout << y[v] + sum(v) << endl;
        }
    }
    return 0;
}
