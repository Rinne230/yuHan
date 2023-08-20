#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define rep(i, j, k) for (int i = (j); i <= (k); i++)
#define per(i, j, k) for (int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
ll n, k;
ll sz[maxn];
ll fact[maxn];
ll infact[maxn];

int qmi(ll a, ll b, ll p)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

void init()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < maxn; ++i)
    {
        fact[i] = fact[i - 1] * i % mod;
        infact[i] = infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
}

int C(int a, int b)
{
    if (a < 0 || b < 0 || a < b)
        return 0;
    return fact[a] % mod * infact[b] % mod * infact[a - b] % mod;
}

vector<int> G[maxn];
ll ans = 0;

void dfs(int u, int fa)
{
    sz[u] = 1;
    for (auto v : G[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
    ans = (ans + 1ll * C(sz[u], k / 2) % mod * C(n - sz[u], k / 2) % mod) % mod;
}

void solve()
{
    cin >> n >> k;
    for (int i = 1, u, v; i <= n - 1; ++i)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if (k & 1)
    {
        cout << 1 << endl;
        return;
    }
    dfs(1, -1);
    cout << 1 + ans * qmi(C(n, k), mod - 2, mod) % mod << endl;
}

int main()
{
    ios;
    init();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}