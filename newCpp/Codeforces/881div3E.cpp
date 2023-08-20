#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef std::pair<ll, ll> PII;
const ll mod = 998244353;
const ll N = 2e6 + 1000;
const ll INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-6;
const ll maxn = 1e5 + 5;
struct SegmentTree{
    ll lc, rc;
    ll dat;
}tree[maxn * 30];
ll tot, root[maxn];
ll a[maxn], b[maxn];
ll n, m, q;
ll cnt;
ll build_tree(ll l, ll r) {
    ll step = tot++;
    if (l == r) {
        tree[step].dat = 0;
        return step;
    }
    ll mid = (l + r) >> 1;
    tree[step].lc = build_tree(l, mid);
    tree[step].rc = build_tree(mid + 1, r);
    tree[step].dat = tree[tree[step].lc].dat + tree[tree[step].rc].dat;

    return step;
}
ll update(ll rt, ll pos, ll val) {
    ll step = tot++;
    ll temp = step;
    tree[step].dat = tree[rt].dat + val;
    ll l = 1, r = cnt;
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (pos <= mid) {
            tree[step].lc = tot++;
            tree[step].rc = tree[rt].rc;
            step = tree[step].lc;
            rt = tree[rt].lc;
            r = mid;
        }
        else{
            tree[step].lc = tree[rt].lc;
            tree[step].rc = tot++;
            step = tree[step].rc;
            rt = tree[rt].rc;
            l = mid + 1;
        }
        tree[step].dat = tree[rt].dat + val;
    }
    return temp;
}
ll query(ll r1, ll r2, ll k) {
    ll l = 1, r = cnt;
    while (l < r) {
        ll mid = (l + r) >> 1;
        ll tmp = tree[tree[r2].lc].dat - tree[tree[r1].lc].dat;
        if (tmp >= k) {
            r1 = tree[r1].lc;
            r2 = tree[r2].lc;
            r = mid;
        }
        else {
            k -= tmp;
            r1 = tree[r1].rc;
            r2 = tree[r2].rc;
            l = mid + 1;
        }
    }
    return l;
}

pair<ll, ll> p[N];
ll tmp[N], sum[N];

void solve()
{
    cin >> n >> q;
    for (ll i = 0; i <= tot + 1; i ++) {
        tree[i].dat = tree[i].lc = tree[i].rc = 0;
        root[i] = 0;
    }
    tot = cnt = 0;
    for (ll i = 1; i <= q; i ++) cin >> p[i].first >> p[i].second;
    cin >> m;
    for (ll i = 1; i <= n; i ++) tmp[i] = 0;
    sum[0] = 0;
    for (ll i = 1, x; i <= m; i++) {
        cin >> x;
        tmp[x] = i;//第x个位置是第i个操作完成的
    }

    for (ll i = 1; i <= n; i ++) {
        a[i] = tmp[i];//a[i]代表的是第i个位置由第几个操作完成
        b[i - 1] = a[i];
    }
    for (ll i = 1; i <= n; i ++) sum[i] = sum[i - 1] + (a[i] == 0);//到i位置，有多少个位置变成了1
    sort(b, b + n);
    cnt = unique(b, b + n) - b;//一共有多少个位置
    tot = 0;
    root[0] = build_tree(1, cnt);
    for (ll i = 1; i <= n; i++) {
        ll tmp = (ll)(lower_bound(b, b + cnt, a[i]) - b) + 1;
        root[i] = update(root[i - 1], tmp, 1);
    }
    ll l, r, k;
    ll ans = INF;
    for (ll i = 1; i <= q; i ++) {
        l = p[i].first, r = p[i].second, k = (r - l + 1) / 2;
        if (k * 2 <= (r - l + 1)) k ++;
        k += (sum[r] - sum[l - 1]);
        if (k > (r - l + 1)) continue;
//        k = (r - l + 1) - k + 1 - (sum[r] - sum[l - 1]);
//        std::cout << "k:" << k << "\n";
//        k = 5;
        ll tmp = query(root[l - 1],root[r], k);
        ll res = b[tmp - 1];
        if (res == 0) res = INF;
        ans = std::min(ans, res);
//        std::cout << res << "\n";
    }
    if (ans == INF) ans = -1;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}