#include <bits/stdc++.h>
using namespace std;
int tree[500010];
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
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        add(i, a);
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (u == 1)
            add(v, w);
        else if (u == 2)
            cout << sum(w) - sum(v - 1) << endl;
    }
    return 0;
}
