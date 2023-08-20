#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

ll sum[maxn << 1], tr[maxn << 3], f[maxn << 1];
struct node
{
    ll l, r;
} a[maxn];

ll query(int rt, int l, int r, int L, int R)
{
    if (L <= l && R >= r)
        return tr[rt];
    int mid = (l + r) / 2;
    ll s = 0;
    if (L <= mid)
        s = max(s, query(rt << 1, l, mid, L, R));
    if (R > mid)
        s = max(s, query(rt << 1 | 1, mid + 1, r, L, R));
    tr[rt] = max(tr[rt << 1], tr[rt << 1 | 1]);
    return s;
}

void update(int rt, int l, int r, int x, ll d)
{
    if (l == r)
    {
        tr[rt] = max(tr[rt], d);
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
        update(rt * 2, l, mid, x, d);
    else
        update(rt * 2 + 1, mid + 1, r, x, d);
    tr[rt] = max(tr[rt * 2], tr[rt * 2 + 1]);
}

int main()
{
    ios;
    ll x, w, n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x >> w;
        a[i].l = x - w;
        a[i].r = x + w;
        sum[++cnt] = x - w;
        sum[++cnt] = x + w;
    }
    sort(a + 1, a + n + 1, [&](node p, node q)
         { return p.r < q.r; });
    sort(sum + 1, sum + cnt + 1);
    ll sz = unique(sum + 1, sum + cnt + 1) - (sum + 1);
    for (int i = 1; i <= n; ++i)
    {
        a[i].l = lower_bound(sum + 1, sum + sz + 1, a[i].l) - sum;
        a[i].r = lower_bound(sum + 1, sum + sz + 1, a[i].r) - sum;
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        f[i] = query(1, 1, sz, 1, a[i].l) + 1;
        ans = max(ans, f[i]);
        update(1, 1, sz, a[i].r, f[i]);
    }
    cout << ans << endl;
    return 0;
}