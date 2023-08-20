#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 1e5 + 10;
typedef long long ll;
struct node
{
    ll a, b, idx;
} e1[maxn], e2[maxn];

bool cmp1(node x, node y)
{
    if (x.a == y.a)
        return x.b > y.b;
    return x.a > y.a;
}

bool cmp2(node x, node y)
{
    if (x.b == y.b)
        return x.a > y.a;
    return x.b > y.b;
}

void solve()
{
    int n;
    cin >> n;
    // map<ll, bool> vis;
    set<int> se;
    for (int i = 0; i < n; ++i)
    {
        cin >> e1[i].a >> e1[i].b;
        e1[i].idx = i;
        e2[i].idx = i;
        e2[i].a = e1[i].a;
        e2[i].b = e1[i].b;
    }

    sort(e1, e1 + n, cmp1);
    sort(e2, e2 + n, cmp2);
    
    ll sum1 = 0, sum2 = 0;
    ll cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
        {
            while (se.count(e1[cnt1].idx)) // while(vis[e1[cnt1].idx])
                cnt1++;
            se.insert(e1[cnt1].idx); // vis[e1[cnt1].idx] = 1;
            sum1 += e1[cnt1].a;
        }
        else
        {
            while (se.count(e2[cnt2].idx)) // while (vis[e2[cnt2].idx])
                cnt2++;
            se.insert(e2[cnt2].idx); // vis[e2[cnt2].idx] = 1;
            sum2 += e2[cnt2].b;
        }
    }
    cout << sum1 - sum2 << endl;
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
/*
2
3
0 2
1 2
3 3
3
1 0
2 3
0 4
*/