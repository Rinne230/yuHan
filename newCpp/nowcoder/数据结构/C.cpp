#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000005;
int pre[MAXN][2], tot, a[MAXN], m, c[MAXN], n, l, r, ans[MAXN];
struct query_node
{
    int id;
    int pos;
    query_node() {}
    query_node(int _id, int _pos)
    {
        id = _id;
        pos = _pos;
    }
};
vector<query_node> q[MAXN];
int lowbit(int x)
{
    return x & -x;
}
void change(int x, int y)   
{
    while (x <= n)
    {
        c[x] += y;
        x += lowbit(x);
    }
    return;
}
int sum(int x)
{
    int ans = 0;
    while (x)
    {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    scanf("%d %*d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d %d", &l, &r);
        q[r].push_back(query_node(i, l));
    }
    for (int i = 1; i <= n; ++i)
    {
        if (pre[a[i]][1])
        {
            change(pre[a[i]][1], -1);
            change(pre[a[i]][0], 1);
        }
        else if (pre[a[i]][0])
        {
            change(pre[a[i]][0], 1);
        }
        pre[a[i]][1] = pre[a[i]][0];
        pre[a[i]][0] = i;
        for (auto &j : q[i])
        {
            ans[j.id] = sum(i) - sum(j.pos - 1);
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}