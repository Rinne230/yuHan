#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
struct tnode
{
    int min, lazy;
    int l, r;
};
struct Segment_Tree
{
    tnode t[4 * MAXN];
    void pushdown(int root)
    {
        if (t[root].lazy != 0)
        {
            t[root].min += t[root].lazy;
            if (t[root].l != t[root].r)
            {
                int ch = root << 1;
                t[ch].lazy += t[root].lazy;
                t[ch + 1].lazy += t[root].lazy;
            }
            t[root].lazy = 0;
        }
    }
    void update(int root)
    {
        int ch = root << 1;
        pushdown(ch);
        pushdown(ch + 1);
        t[root].min = min(t[ch].min, t[ch + 1].min);
    }
    void build(int root, int l, int r, int *A)
    {
        t[root].l = l;
        t[root].r = r;
        t[root].lazy = 0;
        if (l != r)
        {
            int mid = (l + r) >> 1;
            int ch = root << 1;
            build(ch, l, mid, A);
            build(ch + 1, mid + 1, r, A);
            update(root);
        }
        else
            t[root].min = A[l];
    }
    void change(int root, int l, int r, int delta)
    {
        pushdown(root);
        if (l == t[root].l && r == t[root].r)
        {
            t[root].lazy += delta;
            return;
        }
        int mid = (t[root].l + t[root].r) >> 1;
        int ch = root << 1;
        if (r <= mid)
            change(ch, l, r, delta);
        else if (l > mid)
            change(ch + 1, l, r, delta);
        else
        {
            change(ch, l, mid, delta);
            change(ch + 1, mid + 1, r, delta);
        }
        update(root);
    }
    int query_min(int root, int l, int r)
    {
        pushdown(root);
        if (t[root].l == l && t[root].r == r)
        {
            return t[root].min;
        }
        int mid = (t[root].l + t[root].r) >> 1;
        int ch = root << 1;
        if (r <= mid)
            return query_min(ch, l, r);
        else if (l > mid)
            return query_min(ch + 1, l, r);
        else
            return min(query_min(ch, l, mid), query_min(ch + 1, mid + 1, r));
    }
};
Segment_Tree ST;
int l, r, n, m, a[MAXN], x;
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    ST.build(1, 1, n, a);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d %d %d", &x, &l, &r);
        ST.change(1, l, r, -x);
        if (ST.query_min(1, 1, n) < 0)
        {
            printf("-1\n%d\n", i);
            return 0;
        }
    }
    printf("0\n");
    return 0;
}
