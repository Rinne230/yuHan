#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define rep(i, j, k) for (int i = (j); i <= (k); i++)
#define per(i, j, k) for (int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 1 << 20;
const ll mod = 998244353;
const ll inf = 1e18;

int n, m, cnt;
int a[maxn], b[maxn], c[maxn];
priority_queue<int, vector<int>, greater<int>> p, q;
int mnp()
{
    while(1){
        if (p.size() == 0) return -1;
        int u = p.top();
        if (q.size() && q.top() == p.top()) q.pop(), p.pop();
        else return u;
    }
}

void add(int x){
    int tmp = cnt;
    c[++cnt] = x;
    rep(i, 1, tmp) c[++cnt] = x ^ c[i];
    rep(i, tmp + 1, cnt) q.push(c[i]);
}
void solve()
{
    cin >> n;
    m = (1 << n) - 1;
    rep(i, 1, m) cin >> b[i];
    while (p.size()) p.pop();
    while (q.size()) q.pop();
    rep(i, 1, m) p.push(b[i]);
    cnt = 0;
    rep(i, 1, n){
        int u = mnp();
        a[i] = u, add(u);
    }
    if (mnp() != -1) cout << -1 << endl;
    else rep(i, 1, n) cout << a[i] << " \n"[i == n];
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