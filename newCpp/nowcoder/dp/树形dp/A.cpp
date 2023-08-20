/**
 * @file 树的重心
 * @author atrilactose
 * @brief
 * @version 0.1
 *
 * @url: https://ac.nowcoder.com/acm/contest/28258/A
 *
 */
#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
int n;

void solve()
{
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> siz(n + 1);
    int id = 1e9, Min = 1e9;
    function<void(int, int)> dfs = [&](int x, int fa)
    {
        siz[x] = 1;
        for (auto y : g[x])
        {
            if (y == fa)
                continue;
            dfs(y, x);
            siz[x] += siz[y];
            int v = max(siz[x], n - siz[x]);
            if (v <= Min)
            {
                if (v < Min)
                    Min = v, id = x;
                else if (x < id)
                    id = x;
            }
        }
    };
    dfs(0, 0);
    cout << id + 1 << " " << Min - 1 << "\n";
}

int main()
{
    ios;
    while (cin >> n)
    {
        solve();
    }
    return 0;
}