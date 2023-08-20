#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define lowbit(u) u & (-u)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 10;
const ll mod = 998244353;

template <typename Tp>
inline void read(Tp &x)
{
    x = 0;
    int f = 0;
    char ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9'))
        ch = getchar();
    if (ch == '-')
        f = 1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    if (f)
        x = -x;
}
struct node
{
    ll l, r, id;
};

void solve()
{
    ll n, q, R = 0;
    cin >> n;
    vector<int> a(n + 1), pos(n + 1);
    vector<ll> tr(n + 1);
    auto add = [&](int x, int k)
    {
        while (x <= n)
            tr[x] += k, x += lowbit(x);
    };
    auto query = [&](int x)
    {
        ll sum = 0;
        while (x)
            sum += tr[x], x -= lowbit(x);
        return sum;
    };
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    cin >> q;
    vector<node> w(q);
    vector<int> ans(q);
    for (int i = 0; i < q; i++)
    {
        auto &[l, r, id] = w[i];
        cin >> l >> r, id = i;
    }
    sort(w.begin(), w.end(), [&](node &x, node &y)
         { return x.r == y.r ? x.l < y.l : x.r < y.r; });
    for (auto &[l, r, id] : w)
    {
        if (R < r)
        {
            for (int i = 2; i * i <= n + n - 1; i++)
            {
                ll now = i * i;
                for (int j = R + 1; j <= r; j++)
                {
                    if (now - a[j] <= 0 || now - a[j] > n)
                        continue;
                    if (a[j] + a[j] == now)
                        continue;
                    if (pos[now - a[j]] <= j)
                        add(pos[now - a[j]], 1);
                }
            }
            R = r;
        }
        ans[id] = query(r) - query(l - 1);
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
}

int main()
{
    ios;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
1
8
5 7 4 1 8 6 2 3
10
4 5
2 6
1 8
2 7
4 8
3 8
4 7
1 5
2 5
3 7
*/