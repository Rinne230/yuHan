#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
long long A[MAXN];
struct tnode
{
    long long sum[2], lazy[2];
    int l, r;
};
struct Segment_Tree
{
    tnode t[4 * MAXN];
    void init_lazy(int root)
    {
        t[root].lazy[0] = 1;
        t[root].lazy[1] = 0;
    }
    void union_lazy(int fa, int ch)
    {
        long long temp[2];
        temp[0] = t[fa].lazy[0] * t[ch].lazy[0];
        temp[1] = t[fa].lazy[0] * t[ch].lazy[1] + t[fa].lazy[1];
        t[ch].lazy[0] = temp[0];
        t[ch].lazy[1] = temp[1];
    }
    void cal_lazy(int root)
    {
        t[root].sum[1] = t[root].lazy[0] * t[root].lazy[0] * t[root].sum[1] +
                         t[root].lazy[1] * t[root].lazy[1] * (t[root].r - t[root].l + 1) +
                         t[root].lazy[0] * t[root].lazy[1] * 2 * t[root].sum[0];

        t[root].sum[0] = t[root].lazy[0] * t[root].sum[0] +
                         t[root].lazy[1] * (t[root].r - t[root].l + 1);
        return;
    }
    void push_down(int root)
    {
        if (t[root].lazy[0] != 1 || t[root].lazy[1] != 0)
        {
            cal_lazy(root);
            if (t[root].l != t[root].r)
            {
                int ch = root << 1;
                union_lazy(root, ch);
                union_lazy(root, ch + 1);
            }
            init_lazy(root);
        }
    }
    void update(int root)
    {
        int ch = root << 1;
        push_down(ch);
        push_down(ch + 1);
        t[root].sum[0] = t[ch].sum[0] + t[ch + 1].sum[0];
        t[root].sum[1] = t[ch].sum[1] + t[ch + 1].sum[1];
    }
    void build(int root, int l, int r)
    {
        t[root].l = l;
        t[root].r = r;
        init_lazy(root);
        if (l != r)
        {
            int mid = (l + r) >> 1;
            int ch = root << 1;
            build(ch, l, mid);
            build(ch + 1, mid + 1, r);
            update(root);
        }
        else
        {
            t[root].sum[0] = A[l];
            t[root].sum[1] = A[l] * A[l];
        }
    }
    void change(int root, int l, int r, long long delta, int op)
    {
        push_down(root);
        if (l == t[root].l && r == t[root].r)
        {
            t[root].lazy[op] = delta;
            return;
        }
        int mid = (t[root].l + t[root].r) >> 1;
        int ch = root << 1;
        if (r <= mid)
            change(ch, l, r, delta, op);
        else if (l > mid)
            change(ch + 1, l, r, delta, op);
        else
        {
            change(ch, l, mid, delta, op);
            change(ch + 1, mid + 1, r, delta, op);
        }
        update(root);
    }
    long long sum(int root, int l, int r, int op)
    {
        push_down(root);
        if (t[root].l == l && t[root].r == r)
        {
            return t[root].sum[op];
        }
        int mid = (t[root].l + t[root].r) >> 1;
        int ch = root << 1;
        if (r <= mid)
            return sum(ch, l, r, op);
        else if (l > mid)
            return sum(ch + 1, l, r, op);
        else
            return sum(ch, l, mid, op) + sum(ch + 1, mid + 1, r, op);
    }
};
Segment_Tree ST;
int n, m, op, l, r;
long long x;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &A[i]);
    }
    ST.build(1, 1, n);
    for (int _ = 1; _ <= m; ++_)
    {
        scanf("%d %d %d", &op, &l, &r);
        if (op >= 3)
        {
            scanf("%lld", &x);
            ST.change(1, l, r, x, op - 3);
        }
        else
        {
            printf("%lld\n", ST.sum(1, l, r, op - 1));
        }
    }
    return 0;
}