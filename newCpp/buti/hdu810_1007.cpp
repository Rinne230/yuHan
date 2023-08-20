#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int fa[100005];
int find(int x)
{
    if (fa[x] == x)
        return fa[x];
    else
        return fa[x] = find(fa[x]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            fa[i] = i;
        for (int i = 1; i <= m; ++i)
        {
            int x, y;
            cin >> x >> y;
            int xx = find(x), yy = find(y);
            if (xx == yy)
                continue;
            fa[xx] = yy;
        }
        cin >> k;
        int st;
        cin >> st;
        st = find(st);
        bool flag = 1;
        for (int i = 2; i <= k; ++i)
        {
            int ed;
            cin >> ed;
            ed = find(ed);
            flag &= (st == ed);
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}