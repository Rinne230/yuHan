#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> q[k + 1];
    for (int i = 1; i <= k; ++i)
    {
        q[i].push_back(0);
    }
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        q[x].push_back(i);
    }
    for (int i = 1; i <= k; ++i)
    {
        q[i].push_back(n + 1);
    }
    int wz = -1;
    int mi = 1e9;
    int ascnt = 1e9;
    for (int i = 1; i <= k; ++i)
    {
        int temmi = 0;
        vector<int> tem;
        for (int j = 1; j < q[i].size(); ++j)
        {
            tem.push_back(q[i][j] - q[i][j - 1] - 1);
        }

        sort(tem.begin(), tem.end(), greater<int>());
        temmi = tem[0];

        int ma = 0;
        ma = tem[1];
        if ((temmi) / 2 > ma)
            ma = (temmi) / 2;
        mi = min(mi, ma);

        
    }
    cout << mi << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}