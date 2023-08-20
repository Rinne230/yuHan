#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
struct tnode
{
    long long maxx;
    int l, r;
};
int n, m, k, cnt[MAXN];
struct Segment_Tree
{
    tnode t[4 * MAXN];
    void update(int root)
    {
        int ch = root << 1;
        t[root].maxx = max(t[ch].maxx, t[ch + 1].maxx);
    }
    void buildt(int root, int l, int r)
    {
        t[root].l = l;
        t[root].r = r;
        if (l != r)
        {
            int mid = (l + r) >> 1;
            int ch = root << 1;
            buildt(ch, l, mid);
            buildt(ch + 1, mid + 1, r);
            update(root);
        }
        else
        {
            t[root].maxx = m;
            cnt[l] = 0;
        }
    }
    int gao(int val)
    {
        int root = 1;
        while (t[root].l != t[root].r)
        {
            if (t[root << 1].maxx >= val)
            {
                root <<= 1;
            }
            else
            {
                root = root * 2 + 1;
            }
        }
        t[root].maxx -= val;
        ++cnt[t[root].l];
        int ans = t[root].l;
        if (cnt[t[root].l] == k)
        {
            t[root].maxx = 0;
        }
        root >>= 1;
        while (root)
        {
            update(root);
            root >>= 1;
        }
        return ans;
    }
};
Segment_Tree ST;
int x, T;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d %d", &n, &m, &k);
        ST.buildt(1, 1, n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &x);
            if (x > m)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", ST.gao(x));
            }
        }
    }
    return 0;
}