#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const LL N = 2e5 + 10, MOD = 1e9 + 7, INF = 0x3f3f3f3f;
void solve()
{
    int n;
    scanf("%d", &n);
    vector<PII> v;
    for (int i = 1; i <= n; ++i)
    {
        int l, r, a, b;
        scanf("%d%d%d%d", &l, &r, &a, &b);
        v.push_back({l, b});
    }
    sort(v.begin(), v.end());
    vector<int> l, r;
    for (int i = 0; i < v.size();)
    {
        int x = v[i].first, y = v[i].second;
        while (i < v.size() && v[i].first <= y)
        {
            y = max(y, v[i].second);
            ++i;
        }
        l.push_back(x);
        r.push_back(y);
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int x;
        scanf("%d", &x);
        int i = upper_bound(l.begin(), l.end(), x) - 1 - l.begin();
        if (i == -1 || r[i] <= x)
            printf("%d ", x);
        else
            printf("%d ", r[i]);
    }
    printf("\n");
}
int main()
{
    int T = 1;
    scanf("%d", &T);
    while (T--)
    {
        solve();
    }
    return 0;
}