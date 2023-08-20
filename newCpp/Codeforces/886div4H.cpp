#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;

int f[maxn];
ll dis[maxn];
int find(int x)
{
    if (x != f[x])
    {
        int t = f[x];
        f[x] = find(f[x]);
        dis[x] += dis[t];
    }
    return f[x];
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        f[i] = i, dis[i] = 0;
    int flag = 1;
    for (int i = 1; i <= m; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        int fl = find(l), fr = find(r);
        if (fl == fr)
        {
            if (dis[r] - dis[l] != x)
                flag = 0;
        }
        else
        {
            f[fr] = fl;
            dis[fr] = x + dis[l] - dis[r];
            find(r);
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
    int main()
    {
        ios;
        int t;
        cin >> t;
        while (t--)
        {
            solve();
        }
        return 0;
    }
