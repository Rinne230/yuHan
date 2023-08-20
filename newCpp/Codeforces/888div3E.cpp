#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
ll c[maxn];

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> cnt(n, 0);
    vector<ll> source[n];
    queue<ll> q;
    vector<ll> aftcost(n, 0);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0, idx; i < k; i++)
    {
        cin >> idx;
        c[--idx] = 0;
    }

    for (int i = 0, m; i < n; i++)
    {
        cin >> m;
        for (int j = 0, idx; j < m; j++)
        {
            cin >> idx;
            source[--idx].push_back(i);
            cnt[i]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (cnt[i] == 0)
        {
            q.push(i);
            aftcost[i] = c[i];
        }
    }
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (auto v : source[u])
        {
            aftcost[v] += min(c[u], aftcost[u]);
            if (!(--cnt[v]))
                q.push(v);
        }
    }

    for (int i = 0; i < n; i++) cout << (c[i] > aftcost[i] ? aftcost[i] : c[i]) << " ";
    cout << endl;
    return;
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