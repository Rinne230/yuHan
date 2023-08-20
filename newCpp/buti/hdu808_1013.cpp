#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

ll a[maxn], t[maxn], n;

int lowbit(int x)
{
    return x & -x;
}

int add(int x)
{
    while (x <= n)
    {
        t[x]++;
        x += lowbit(x);
    }
}

int sum(int x)
{
    int res = 0;
    while (x >= 1)
    {
        res += t[x];
        x -= lowbit(x);
    }
}

void solve()
{
    int n;
    ll cnt = 0, base = 0;
    cin >> n;
    vector<ll> t(n + 1), a(n + 1);
    auto add = [&](int x, int k)
    {
        while (x <= n)
            t[x] += k, x += lowbit(x);
    };
    auto query = [&](int x)
    {
        ll sum = 0;
        while (x)
            sum += t[x], x -= lowbit(x);
        return sum;
    };
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt += query(n) - query(a[i]);
        add(a[i], 1);
    }
    if (n == 1)
    {
        cout << 0 << ' ' << 1 << endl;
        return;
    }
    if (cnt & 1)
        cout << "2 ";
    else
        cout << "0 ";
    auto m = n;
    while (m)
    {
        base = base << 1 | 1;
        m >>= 1;
    }
    base ^= (!(cnt & 1)) << 1;
    cout << base << "\n";
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