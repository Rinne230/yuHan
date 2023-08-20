#include <bits/stdc++.h>
#define int long long
#define MAXN 1000086

using namespace std;
int n, m;
int a[MAXN];
inline int read()
{
    register int x = 0;
    register bool f = 0;
    register char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = 1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 3) + (x << 1) + c - 48;
        c = getchar();
    }
    return f ? -x : x;
}
struct T
{
    int l, r, val, maxn;
} t[MAXN];

void update(int node)
{
    t[node].val = t[node << 1].val + t[node << 1 | 1].val;
    t[node].maxn = max(t[node << 1].maxn, t[node << 1 | 1].maxn);
}

void build(int l, int r, int node)
{
    t[node].l = l;
    t[node].r = r;
    if (l == r)
    {
        t[node].val = a[l];
        t[node].maxn = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, node << 1);
    build(mid + 1, r, node << 1 | 1);
    update(node);
}

void change(int l, int r, int node)
{
    if (t[node].l == t[node].r)
    {
        t[node].val = sqrt(t[node].val);
        t[node].maxn = sqrt(t[node].maxn);
        return;
    }
    int mid = (t[node].l + t[node].r) >> 1;
    if (l <= mid && t[node << 1].maxn > 1)
        change(l, r, node << 1);
    if (r > mid && t[node << 1 | 1].maxn > 1)
        change(l, r, node << 1 | 1);
    update(node);
}

int ask(int l, int r, int node)
{
    if (l <= t[node].l && t[node].r <= r)
    {
        return t[node].val;
    }
    int mid = (t[node].l + t[node].r) >> 1;
    int ans = 0;
    if (l <= mid)
        ans += ask(l, r, node << 1);
    if (r > mid)
        ans += ask(l, r, node << 1 | 1);
    return ans;
}

signed main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    m = read();
    build(1, n, 1);
    int op, l, r;
    for (int i = 1; i <= m; i++)
    {
        op = read();
        l = read();
        r = read();
        if (l > r)
            swap(l, r);

        if (op == 2)
        {
            change(l, r, 1);
        }
        else
        {
            cout << ask(l, r, 1) << '\n';
        }
    }
    cout << endl;

    return 0;
}